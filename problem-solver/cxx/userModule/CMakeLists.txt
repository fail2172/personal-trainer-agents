set(SOURCES
        "agent/CreateUserAgent.cpp"
        "agent/SearchUserAgent.cpp"
        "agent/UpdateUserAgent.cpp"
        "generator/UserDiseasesGenerator.cpp"
        "generator/UserGenerator.cpp"
        "keynodes/UserKeynodes.cpp"
        "manager/CreateUserManager.cpp"
        "manager/UpdateUserManager.cpp"
        "searcher/LoginSearcher.cpp"
        "searcher/UserSearcher.cpp"
        "template/DiseaseListTemplates.hpp"
        "template/DiseaseListTemplates.cpp"
        "template/UserParamsTemplates.cpp"
        "template/UserTemplates.cpp"
        "UserModule.cpp"
        )

set(HEADERS
        "agent/CreateUserAgent.hpp"
        "agent/SearchUserAgent.hpp"
        "agent/UpdateUserAgent.hpp"
        "generator/UserDiseasesGenerator.hpp"
        "generator/UserGenerator.hpp"
        "keynodes/UserKeynodes.hpp"
        "manager/CreateUserManager.hpp"
        "manager/UpdateUserManager.hpp"
        "searcher/LoginSearcher.hpp"
        "searcher/UserSearcher.hpp"
        "template/UserTemplates.hpp"
        "template/UserParamsTemplates.hpp"
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
