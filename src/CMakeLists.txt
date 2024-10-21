cmake_minimum_required(VERSION 3.16)

project(QOwnTodolist VERSION 0.1 LANGUAGES CXX)

include(commonsettings)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS REQUIRED
    LinguistTools
    Core
    Widgets
    Gui
    Sql
    Svg
    Network
    Xml
)
# Translation files
set(TS_FILES languages/QOwnTodolist_zh_CN.ts)

file(GLOB_RECURSE srcs ${PROJECT_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE headers ${PROJECT_SOURCE_DIR}/*.h)

set(PROJECT_SOURCES
        ${srcs}
        ${headers}
        ${TS_FILES}
)

qt_add_executable(QOwnTodolist
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
)
qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})


target_link_libraries(QOwnTodolist PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Sql
)
target_compile_definitions(QOwnTodolist PRIVATE -D_BUILDING_QX_QOT)#添加构建参数表明正在构建此项目

if(COMMAND target_precompile_headers)
   target_precompile_headers(QOwnTodolist PRIVATE ./core/database/precompiled.h)
endif() # (COMMAND target_precompile_headers)
include(QxOrm)
include(ElaWidgetTools)

target_include_directories(QOwnTodolist PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
)

set_target_properties(QOwnTodolist PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    #WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS QOwnTodolist
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

qt_finalize_executable(QOwnTodolist)

