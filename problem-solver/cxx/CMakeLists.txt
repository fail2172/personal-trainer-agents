set(SC_COMMON_MODULE_SRC "${CMAKE_CURRENT_LIST_DIR}/commonModule")
set(SC_USER_MODULE_SRC "${CMAKE_CURRENT_LIST_DIR}/userModule")
set(SC_NUTRITION_MODULE_SRC "${CMAKE_CURRENT_LIST_DIR}/nutritionModule")

add_subdirectory(commonModule)
add_subdirectory(userModule)
add_subdirectory(nutritionModule)
