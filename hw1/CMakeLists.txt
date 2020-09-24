# 指定最低的版本号
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# project 名称
project(AlgorithmHW1)

message("[usr] Project: AlgorithmHW1")               # 打印相关消息消息 
message("[usr] Project Directory: ${PROJECT_SOURCE_DIR}")
message("[usr] CMAKE_CURRENT_SOURCE_DIR Directory: ${CMAKE_CURRENT_SOURCE_DIR}")
if(UNIX)
    add_compile_options(-std=c++11)
    #aux_source_directory(${PROJECT_SOURCE_DIR}/src MAINCPP)
    set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
    add_executable(main ../src/hw1.cpp)
else()
    message(FATAL_ERROR "It doesn't support the ${CMAKE_SYSTEM} right now!")
endif()