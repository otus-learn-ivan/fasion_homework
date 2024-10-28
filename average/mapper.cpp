

#include <map>
#include <functional>
#include <span>
#include <iostream>
#include <string>
#include <memory>
//#include "catboost/c_api.h"

std::vector<std::function<double( std::span<int>&)>> it_is{
    []( std::span<int>& arg){return 0.01;},
    []( std::span<int>& arg){return 0.02;},
    []( std::span<int>& arg){return 0.03;},
    []( std::span<int>& arg){return 0.04;},
    []( std::span<int>& arg){return 0.05;},
    []( std::span<int>& arg){return 0.06;},
    []( std::span<int>& arg){return 0.07;},
    []( std::span<int>& arg){return 0.08;},
    []( std::span<int>& arg){return 0.09;},
    []( std::span<int>& arg){return 0.00;},
};

class BinaryClassifier {
public:

    using features_t = std::vector<float>;

    virtual ~BinaryClassifier() {}

    virtual float predict_proba(const features_t&) const = 0;
};

class CatboostClassifier: public BinaryClassifier {
public:
    CatboostClassifier(const std::string& modepath);

    ~CatboostClassifier() override = default;

     std::vector<float> predict_proba(const features_t&) const override;

private:
    std::unique_ptr<ModelCalcerHandle, decltype(&ModelCalcerDelete)> model_;
};

CatboostClassifier::CatboostClassifier(const std::string& modepath)
    : model_{ModelCalcerCreate(), ModelCalcerDelete} {
    // model_ = ModelCalcerCreate();
    if (!LoadFullModelFromFile(model_.get(), modepath.c_str())) {
        std::stringstream ss;
        ss << "LoadFullModelFromFile error message:" << GetErrorString();
        throw std::runtime_error{ss.str()};
    }
    if (!SetPredictionType(model_.get(), APT_PROBABILITY)) {
        std::stringstream ss;
        ss << "LoadFullModelFromFile error message:" << GetErrorString();
        throw std::runtime_error{ss.str()};
    }
}

std::vector<float> CatboostClassifier::predict_proba(const features_t& features) const {
    double result[10];
    if (!CalcModelPredictionSingle(model_.get(), features.data(), features.size(), nullptr, 0, result, 10)) {
        std::stringstream ss;
        ss << "CalcModelPredictionFlat error message:" << GetErrorString();
        throw std::runtime_error{ss.str()};
    }
    return std::vector<double> {std::begin(result), std::end(result)};
}

bool read_features(std::istream& stream, BinaryClassifier::features_t& features) {
    std::string line;
    std::getline(stream, line);

    features.clear();
    std::istringstream linestream{line};
    double value;
    while (linestream, linestream >> value) {
        features.push_back(value);
    }
    return stream.good();
}

std::vector<float> read_vector(std::istream& stream) {
    std::vector<float> result;

    std::copy(std::istream_iterator<float>(stream),
              std::istream_iterator<float>(),
              std::back_inserter(result));
    return result;
}

std::vector<double> what_is_it( std::span< elem,){

    //std::unique_ptr<ModelCalcerHandle, decltype(&ModelCalcerDelete)> model_;

    std::vector<double> ansver;
    for(auto& func_: it_is){
        auto t = func_(elem);
        ansver.push_back(t);
    }
    return ansver;
}

#include <fstream>
#include <sstream>
#include <cstdlib>
#include <span>
int main(int argc, char ** argv)
{


    std::string name_file_test = argv[1];
    std::cout << name_file_test << "\n";
    std::vector <std::vector<int>> vk_test;
    std::string line;
    std::ifstream in(name_file_test);  // открываем файл для чтения
    if (in.is_open())
    {
        while (std::getline(in, line))
        {
            //std::cout << line << std::endl;
            std::stringstream ss(line);
            std::string t;
            char del = ',';
            std::vector<int> buf;
            while (getline(ss, t, del))
                buf.push_back(atoi(t.c_str()));
            vk_test.push_back(buf);
        }
    }
    in.close();  // закрываем файл
    std::cout <<"vk_test.size: " << vk_test.size() << std::endl;
    std::vector<std::pair<int,std::vector<double>>> ansver;
    for(auto& elem: vk_test){
         ansver.push_back({elem[0], what_is_it(std::span(elem.begin()+1,elem.end()))});
    }

    long int true_ansver{};

    for(const auto& pair: ansver){
        auto max_trast = std::max_element(pair.second.begin(),pair.second.end())-pair.second.begin();
        std::cout << pair.first <<" " << max_trast <<" "
                  << std::boolalpha << (pair.first == max_trast)<<"\n";
        if(pair.first == max_trast) {true_ansver++;}
    }
    std::cout <<"true_ansver: " << true_ansver <<"\n";
    return 0;
}

#endif

