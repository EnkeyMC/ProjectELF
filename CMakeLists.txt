cmake_minimum_required(VERSION 3.1)

project(ProjectELF LANGUAGES CXX)
set(PROJECT_NAME_TESTS ${PROJECT_NAME}_tests)

set(SOURCE_FILES
        src/gui/main.cpp
        src/gui/qml.qrc
        src/gui/diagram/DiagramScene.cpp
        include/gui/diagram/DiagramScene.h
        src/core/models/ELFModel.cpp
        include/core/models/ELFModel.h
        src/gui/diagram/DiagramNode.cpp
        include/gui/diagram/DiagramNode.h
        src/gui/diagram/nodes/DiagramHeaderNode.cpp
        include/gui/diagram/nodes/DiagramHeaderNode.h
        src/gui/diagram/DiagramLayout.cpp
        include/gui/diagram/DiagramLayout.h
        src/gui/diagram/CondensedDiagramLayout.cpp
        include/gui/diagram/CondensedDiagramLayout.h
        src/gui/diagram/nodes/DiagramSectionHeaderTableNode.cpp
        include/gui/diagram/nodes/DiagramSectionHeaderTableNode.h
        src/gui/diagram/ProportionalDiagramLayout.cpp
        include/gui/diagram/ProportionalDiagramLayout.h
        src/gui/diagram/nodes/DiagramProgramHeaderTableNode.cpp
        include/gui/diagram/nodes/DiagramProgramHeaderTableNode.h
        src/gui/diagram/nodes/DiagramELFNode.cpp
        include/gui/diagram/nodes/DiagramELFNode.h
        src/core/models/ELFModelItem.cpp
        include/core/models/ELFModelItem.h
        src/core/models/ELFHeaderModelItem.cpp
        include/core/models/ELFHeaderModelItem.h
        src/core/ModelBase.cpp
        include/core/ModelBase.h
        src/core/models/ELFSectionHeaderTableModelItem.cpp
        include/core/models/ELFSectionHeaderTableModelItem.h
        src/core/models/ELFSectionHeaderModelItem.cpp
        include/core/models/ELFSectionHeaderModelItem.h
        src/core/models/ELFProgramHeaderTableModelItem.cpp
        include/core/models/ELFProgramHeaderTableModelItem.h
        src/core/models/ELFProgramHeaderModelItem.cpp
        include/core/models/ELFProgramHeaderModelItem.h
        src/core/models/ELFSectionModelItem.cpp
        include/core/models/ELFSectionModelItem.h
        src/core/models/ELFSegmentModelItem.cpp
        include/core/models/ELFSegmentModelItem.h
        src/core/models/OpenFilesModel.cpp
        include/core/models/OpenFilesModel.h
        src/core/ELFValueConverter.cpp
        include/core/ELFValueConverter.h
        src/gui/diagram/nodes/DiagramSectionHeaderNode.cpp
        include/gui/diagram/nodes/DiagramSectionHeaderNode.h
        src/core/models/ELFIndexedModelItem.cpp
        include/core/models/ELFIndexedModelItem.h
        src/gui/diagram/nodes/DiagramProgramHeaderNode.cpp
        include/gui/diagram/nodes/DiagramProgramHeaderNode.h
        src/gui/diagram/nodes/DiagramSectionNode.cpp
        include/gui/diagram/nodes/DiagramSectionNode.h
        src/gui/diagram/nodes/DiagramSegmentNode.cpp
        include/gui/diagram/nodes/DiagramSegmentNode.h
        include/core/VerticalBinaryTree.h
        include/core/IVerticalBinaryTreeNode.h
        include/core/IMouseListener.h include/gui/diagram/IDiagramMouseListener.h include/gui/diagram/DiagramStyle.h include/gui/diagram/nodes/DiagramTableNode.h)


set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core Quick REQUIRED)

# Google Tests
add_subdirectory(ext/gtest)

enable_testing()

set(TEST_FILES
        tests/core/VerticalBinaryTreeTest.cpp)

add_executable(${PROJECT_NAME_TESTS} ${TEST_FILES})

target_link_libraries(${PROJECT_NAME_TESTS} GTest::GTest GTest::Main Qt5::Core Qt5::Quick)
target_include_directories(${PROJECT_NAME_TESTS} PRIVATE ${PROJECT_SOURCE_DIR}/include)

add_test(Tests ${PROJECT_NAME_TESTS})

#add_custom_command(TARGET ${PROJECT_NAME}_test PRE_BUILD
#        COMMAND ${CMAKE_COMMAND} -E copy_directory
#        ${CMAKE_SOURCE_DIR}/tests/test_files ${PROJECT_BINARY_DIR}/test_files)

add_subdirectory(libelf)

target_link_libraries(${PROJECT_NAME_TESTS} libelf)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_compile_definitions(${PROJECT_NAME} PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core Qt5::Quick libelf)
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)

