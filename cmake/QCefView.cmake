add_library(QCefView SHARED IMPORTED)#创造QCefView库
set(QCefView_dir "D:/Program/lib/QCefView.windows.x86_64-v1.1.0")#设置QCefView库的路径
# 检查目标平台
if(WIN32)
    # 针对Windows的配置
    set_target_properties(QCefView PROPERTIES
        IMPORTED_LOCATION             ${QCefView_dir}/bin/QCefViewd.dll
        IMPORTED_IMPLIB               ${QCefView_dir}/lib/QCefView.lib
        INTERFACE_INCLUDE_DIRECTORIES ${QCefView_dir}/include
    )#设置QCefView库的路径
    file(COPY ${QCefView_dir}/lib/libQCefViewd.dll DESTINATION ${CMAKE_BINARY_DIR}/src/Debug)
elseif(ANDROID)
    # 针对Android的配置
    set_target_properties(QCefView PROPERTIES
        IMPORTED_LOCATION             ${QCefView_dir}/lib/libQCefViewd.so
        #IMPORTED_IMPLIB               ${QCefView_dir}/lib/libQCefViewd.dll.a
        INTERFACE_INCLUDE_DIRECTORIES ${QCefView_dir}/include
    )#设置QCefView库的路径
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE QCefView)#将QCefView库链接到项目
