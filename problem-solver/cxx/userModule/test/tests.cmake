make_tests_from_folder(${CMAKE_CURRENT_LIST_DIR}/units
        NAME user_control_starter
        DEPENDS sc-agents-common sc-builder-lib userModule
        INCLUDES ${SC_MEMORY_SRC}/tests/sc-memory/_test ${CMAKE_CURRENT_LIST_DIR}/..)

add_definitions(-DUSER_CONTROL_MODULE_TEST_SRC_PATH="${CMAKE_CURRENT_LIST_DIR}")