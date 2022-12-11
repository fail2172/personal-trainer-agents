set(SOURCES
        "keynodes/NutritionKeynodes.cpp"
        "NutritionModule.cpp"
        "agent/CreateNutritionAgent.cpp"
        "manager/CreateNutritionManager.cpp"
        "generator/NutritionGenerator.cpp"
        "searcher/NutritionSearcher.cpp"
        )

set(HEADERS
        "agent/CreateNutritionAgent.hpp"
        "keynodes/NutritionKeynodes.hpp"
        "NutritionModule.hpp"
        "manager/CreateNutritionManager.hpp"
        "searcher/NutritionSearcher.hpp"
        "generator/NutritionGenerator.hpp"
        agent/SearchNutritionAgent.cpp agent/SearchNutritionAgent.hpp template/NutritionTemplates.cpp template/NutritionTemplates.hpp)

include_directories(
        ${CMAKE_CURRENT_LIST_DIR}
        ${SC_MEMORY_SRC}
        ${SC_KPM_SRC}
        ${SC_TOOLS_SRC}
        ${SC_COMMON_MODULE_SRC}
        ${SC_USER_MODULE_SRC}
)

add_library(nutritionModule SHARED ${SOURCES} ${HEADERS})

target_link_libraries(
        nutritionModule
        sc-memory
        sc-agents-common
        commonModule
        userModule
)

sc_codegen_ex(nutritionModule ${CMAKE_CURRENT_LIST_DIR} ${CMAKE_CURRENT_LIST_DIR}/generated)

#if (${SC_BUILD_TESTS})
#    include(${CMAKE_CURRENT_LIST_DIR}/test/tests.cmake)
#endif ()
