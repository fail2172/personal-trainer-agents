set(SOURCES
        "extractor/ArgumentExtractor.cpp"
        "handler/LinkHandler.cpp"
        "keynodes/Keynodes.cpp"
        "utils/ActionUtils.cpp"
        "CommonModule.cpp"
        )

set(HEADERS
        "extractor/ArgumentExtractor.hpp"
        "handler/LinkHandler.hpp"
        "keynodes/Keynodes.hpp"
        "manager/AgentManager.hpp"
        "utils/ActionUtils.hpp"
        "CommonModule.hpp"
        )

include_directories(
        ${CMAKE_CURRENT_LIST_DIR}
        ${SC_MEMORY_SRC}
        ${SC_KPM_SRC}
        ${SC_TOOLS_SRC})

add_library(commonModule SHARED ${SOURCES} ${HEADERS})

target_link_libraries(commonModule sc-memory sc-agents-common)

sc_codegen_ex(commonModule ${CMAKE_CURRENT_LIST_DIR} ${CMAKE_CURRENT_LIST_DIR}/generated)
