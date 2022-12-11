set(SOURCES
        "agent/CreateNutritionAgent.cpp"
        "agent/SearchNutritionAgent.cpp"
        "generator/NutritionGenerator.cpp"
        "keynodes/NutritionKeynodes.cpp"
        "manager/CreateNutritionManager.cpp"
        "searcher/NutritionSearcher.cpp"
        "template/NutritionTemplates.cpp"
        "NutritionModule.cpp"
        )

set(HEADERS
        "agent/CreateNutritionAgent.hpp"
        "agent/SearchNutritionAgent.hpp"
        "generator/NutritionGenerator.hpp"
        "keynodes/NutritionKeynodes.hpp"
        "manager/CreateNutritionManager.hpp"
        "searcher/NutritionSearcher.hpp"
        "template/NutritionTemplates.hpp"
        "NutritionModule.hpp"
        )

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
