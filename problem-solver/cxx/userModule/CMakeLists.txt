set(SOURCES
        "agent/CreateUserAgent.cpp"
        "agent/SearchUserAgent.cpp"
        "generator/UserGenerator.cpp"
        "keynodes/UserKeynodes.cpp"
        "manager/CreateUserManager.cpp"
        "searcher/LoginSearcher.cpp"
        "searcher/UserSearcher.cpp"
        "template/UserTemplates.cpp"
        "UserModule.cpp"
        )

set(HEADERS
        "agent/CreateUserAgent.hpp"
        "agent/SearchUserAgent.hpp"
        "generator/UserGenerator.hpp"
        "keynodes/UserKeynodes.hpp"
        "manager/CreateUserManager.hpp"
        "searcher/LoginSearcher.hpp"
        "searcher/UserSearcher.hpp"
        "template/UserTemplates.hpp"
        "UserModule.hpp"
        )

include_directories(
        ${CMAKE_CURRENT_LIST_DIR}
        ${SC_MEMORY_SRC}
        ${SC_KPM_SRC}
        ${SC_TOOLS_SRC}
        ${SC_COMMON_MODULE_SRC}
)

add_library(userModule SHARED ${SOURCES} ${HEADERS})

target_link_libraries(
        userModule
        sc-memory
        sc-agents-common
        commonModule
)

sc_codegen_ex(userModule ${CMAKE_CURRENT_LIST_DIR} ${CMAKE_CURRENT_LIST_DIR}/generated)

if (${SC_BUILD_TESTS})
    include(${CMAKE_CURRENT_LIST_DIR}/test/tests.cmake)
endif ()
