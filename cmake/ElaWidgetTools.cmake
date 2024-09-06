add_library(ElaWidgetTools SHARED IMPORTED)#创造QxOrm库
set(ElaWidgetTools_dir "D:/Program/lib/QxOrm-1.4.9")#设置QxOrm库的路径
# 检查目标平台
if(WIN32)
    # 针对Windows的配置
    set_target_properties(QxOrm PROPERTIES
        IMPORTED_LOCATION             ${ElaWidgetTools_dir}/lib/libQxOrmd.dll
        IMPORTED_IMPLIB               ${ElaWidgetTools_dir}/lib/libQxOrmd.dll.a
        INTERFACE_INCLUDE_DIRECTORIES ${ElaWidgetTools_dir}/include
    )#设置QxOrm库的路径
    file(COPY  ${ElaWidgetTools_dir}/lib/libQxOrmd.dll DESTINATION ${CMAKE_BINARY_DIR}src/Debug)
elseif(ANDROID)
    # 针对Android的配置
    set_target_properties(QxOrm PROPERTIES
        IMPORTED_LOCATION             ${ElaWidgetTools_dir}/lib/libQxOrmd.so
        #IMPORTED_IMPLIB               ${ElaWidgetTools_dir}/lib/libQxOrmd.dll.a
        INTERFACE_INCLUDE_DIRECTORIES ${ElaWidgetTools_dir}/include
    )#设置QxOrm库的路径
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE QxOrm)#将QxOrm库链接到项目
