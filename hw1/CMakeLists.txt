# 指定最低的版本号
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# project 名称
project(AlgorithmHW1)

message("[usr] Project: AlgorithmHW1")               # 打印相关消息消息 
message("[usr] Project Directory: ${PROJECT_SOURCE_DIR}")
message("[usr] CMAKE_CURRENT_SOURCE_DIR Directory: ${CMAKE_CURRENT_SOURCE_DIR}")
message("[usr] Plateform: ${CMAKE_SYSTEM}")
if(UNIX)
    # 增加编译选项
    add_compile_options(-std=c++11)

    # 自动搜索cpp文件
    aux_source_directory(${PROJECT_SOURCE_DIR}/src MAINCPP)
    message("[usr] CPP files: ${MAINCPP}")
    # 设定可执行文件的输出位置
    set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

    # 生成可执行文件
    add_executable(main ${MAINCPP})
else()
    # 不支持linux以外的平台
    message(FATAL_ERROR "It doesn't support the ${CMAKE_SYSTEM} right now!")
endif()