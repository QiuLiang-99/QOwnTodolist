cmake_minimum_required(VERSION 3.16)

project(EduScheduleImporter VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS REQUIRED
    LinguistTools
    Core
    Widgets
    Gui
    Sql
    Network
)
find_package(Qt6 REQUIRED COMPONENTS WebEngineWidgets)
file(GLOB_RECURSE srcs ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE headers ${PROJECT_SOURCE_DIR}/src/*.h)
set(PROJECT_SOURCES
        ${srcs}
        ${headers}
        #${TS_FILES}
)
qt_add_executable(EduScheduleImporter
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
)
target_link_libraries(EduScheduleImporter PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Sql
)
target_link_libraries(EduScheduleImporter PRIVATE Qt6::WebEngineWidgets)
target_include_directories(EduScheduleImporter PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
)
set_target_properties(EduScheduleImporter PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    #WIN32_EXECUTABLE TRUE
)
include(GNUInstallDirs)
install(TARGETS EduScheduleImporter
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
qt_finalize_executable(EduScheduleImporter)