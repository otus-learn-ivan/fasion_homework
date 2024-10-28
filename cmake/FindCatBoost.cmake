find_library(CatBoost_LIBRARY NAMES catboostmodel catboost PATHS /usr/local/lib)
   find_path(CatBoost_INCLUDE_DIR catboost/model.h PATHS /usr/local/include)

   if (CatBoost_LIBRARY AND CatBoost_INCLUDE_DIR)
     set(CatBoost_FOUND TRUE)
     set(CatBoost_INCLUDE_DIRS ${CatBoost_INCLUDE_DIR})
     set(CatBoost_LIBRARIES ${CatBoost_LIBRARY})
   endif()

   # Сообщение об ошибке, если библиотека не найдена
   if (NOT CatBoost_FOUND)
     message(FATAL_ERROR "Could not find CatBoost. Please check if the library is installed.")
   endif()
   
