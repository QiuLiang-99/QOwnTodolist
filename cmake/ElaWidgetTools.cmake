add_library(ElaWidgetTools SHARED IMPORTED)#创造ElaWidgetTools库
set(ElaWidgetTools_dir "D:/Program/lib/ElaWidgetTools")#设置ElaWidgetTools库的路径
# 检查目标平台
if(WIN32)
    # 针对Windows的配置
    set_target_properties(ElaWidgetTools PROPERTIES
        IMPORTED_LOCATION             ${ElaWidgetTools_dir}/lib/elawidgettools.dll
        IMPORTED_IMPLIB               ${ElaWidgetTools_dir}/lib/libelawidgettools.a
        INTERFACE_INCLUDE_DIRECTORIES ${ElaWidgetTools_dir}/include
    )
    file(COPY ${ElaWidgetTools_dir}/lib/elawidgettools.dll DESTINATION ${CMAKE_BINARY_DIR}src/Debug)
elseif(ANDROID)
    # 针对Android的配置
    # ElaWidgetTools 无安卓版本
    message(WARNING "ElaWidgetTools does not have an Android version.")
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE ElaWidgetTools)#将ElaWidgetTools库链接到项目
