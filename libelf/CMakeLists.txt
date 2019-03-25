project(libelf LANGUAGES CXX)

set(PROJECT_NAME_TESTS ${PROJECT_NAME}_tests)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        src/ELF.cpp
        src/ELFReader.cpp
        src/ELFWriter.cpp
        src/ELFIssue.cpp
        src/ELFHeader.cpp
        src/ELFIssuesBySeverity.cpp
        src/ELFSectionHeader.cpp tests/ELFReaderTest.cpp)

add_library(${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

set(TEST_FILES
        tests/ELFTest.cpp
        tests/ELFIssuesBySeverityTest.cpp
        tests/Memstream.h tests/MemstreamTest.cpp)

add_executable(${PROJECT_NAME_TESTS} ${TEST_FILES} ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME_TESTS} PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME_TESTS} GTest::GTest GTest::Main)

add_test(LibElfTests ${PROJECT_NAME_TESTS})
