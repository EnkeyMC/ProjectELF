cmake_minimum_required(VERSION 3.1)

project(ProjectELF LANGUAGES CXX)
set(PROJECT_NAME_TESTS ${PROJECT_NAME}_tests)

set(SOURCE_FILES
        src/gui/main.cpp
        src/gui/qml.qrc
        src/gui/diagram/DiagramScene.cpp
        include/gui/diagram/DiagramScene.h
        src/gui/diagram/DiagramModel.cpp include/gui/diagram/DiagramModel.h)

# Google Tests
add_subdirectory(ext/gtest)

enable_testing()

set(TEST_FILES
        tests/test.cpp
)

add_executable(${PROJECT_NAME_TESTS} ${TEST_FILES})

target_link_libraries(${PROJECT_NAME_TESTS} GTest::GTest GTest::Main)

add_test(Tests ${PROJECT_NAME_TESTS})

#add_custom_command(TARGET ${PROJECT_NAME}_test PRE_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy_directory
#        ${CMAKE_SOURCE_DIR}/tests/test_files ${PROJECT_BINARY_DIR}/test_files)

add_subdirectory(libelf)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core Quick REQUIRED)


add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_compile_definitions(${PROJECT_NAME} PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core Qt5::Quick libelf)
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)

