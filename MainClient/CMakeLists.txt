cmake_minimum_required(VERSION 3.17)
project(MainClient)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread) #убирает ошибку "thread func_threadundefined reference to `pthread_create'"

add_executable(MainClient MainClient.cpp Client.cpp)
target_link_libraries(MainClient mysqlcppconn) #убирает ошибку "undefined reference to `get_driver_instance'"