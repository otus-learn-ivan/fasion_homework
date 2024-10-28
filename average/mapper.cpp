

#include <map>
#include <functional>
#include <span>
#include <iostream>
#include <istream>
#include <string>
#include <memory>
#include <sstream>
#include "catboost/c_api.h"




class BinaryClassifier {
public:

    using features_t = std::vector<float>;

    virtual ~BinaryClassifier() {}

    virtual std::vector<float> predict_proba(const features_t&) const = 0;
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
    return std::vector<float> {std::begin(result), std::end(result)};
}
//bool read_features(std::istream& stream, BinaryClassifier::features_t& features) {
//    std::string line;
//    std::getline(stream, line);
bool read_features(std::string& line, BinaryClassifier::features_t& features) {

    features.clear();
    std::istringstream linestream{line};
    double value;
    while (linestream, linestream >> value) {
        features.push_back(value);
    }
    return true;// stream.good();
}


#if 0
std::vector<float> read_vector(std::istream& stream) {
    std::vector<float> result;

    std::copy(std::istream_iterator<float>(stream),
              std::istream_iterator<float>(),
              std::back_inserter(result));
    return result;
}
#endif
std::vector<float> what_is_it( std::string test_data,std::string model_file){

    //std::unique_ptr<ModelCalcerHandle, decltype(&ModelCalcerDelete)> model_;


    CatboostClassifier predictor{model_file};
    auto features = CatboostClassifier::features_t{};

    read_features(test_data,features);
    std::vector<float> ansver = predictor.predict_proba(features);
    return ansver;
}

#include <fstream>
#include <sstream>
#include <cstdlib>
#include <span>
int main(int argc, char ** argv)
{


    std::string name_file_test = argv[1];
    std::string name_file_model = argv[2];
    std::cout << name_file_test << "\n";
    std::vector <std::string> vk_test;
    std::string line;
    std::ifstream in(name_file_test);  // открываем файл для чтения
    if (in.is_open())
    {
        while (std::getline(in, line))
        {
            vk_test.push_back(line);

            // //std::cout << line << std::endl;
            // std::stringstream ss(line);
            // std::string t;
            // char del = ',';
            // std::vector<int> buf;
            // while (getline(ss, t, del))
            //     buf.push_back(atoi(t.c_str()));
            // vk_test.push_back(buf);
        }
    }
    in.close();  // закрываем файл
    std::cout <<"vk_test.size: " << vk_test.size() << std::endl;
    std::vector<std::pair<std::string,std::vector<float>>> ansver;
    for(auto& elem: vk_test){
        size_t pos = elem.find(',');
        ansver.push_back({elem.substr(0, pos), what_is_it(elem.substr(pos+1),name_file_model)});
//         ansver.push_back({substr(0, pos), what_is_it(std::span(elem.begin()+1,elem.end()))});
    }

    long int true_ansver{};

    for(const auto& pair: ansver){
        auto max_trast = std::max_element(pair.second.begin(),pair.second.end())-pair.second.begin();
        std::cout << pair.first <<" " << max_trast <<" "
                  << std::boolalpha << (atoi(pair.first.c_str()) == max_trast)<<"\n";
        if(atoi(pair.first.c_str()) == max_trast) {true_ansver++;}
    }
    std::cout <<"true_ansver: " << true_ansver <<"\n";
    return 0;
}


