project(libelf LANGUAGES CXX)

set(PROJECT_NAME_TESTS ${PROJECT_NAME}_tests)

set(SOURCE_FILES
        src/Dummy.cpp
)

add_library(${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)



set(TEST_FILES
        tests/test.cpp
)

add_executable(${PROJECT_NAME_TESTS} ${TEST_FILES})

target_link_libraries(${PROJECT_NAME_TESTS} GTest::GTest GTest::Main)

add_test(LibElfTests ${PROJECT_NAME_TESTS})
