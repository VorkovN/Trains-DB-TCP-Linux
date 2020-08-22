cmake_minimum_required(VERSION 3.17)
project(MainServer)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread) #убирает ошибку "thread func_threadundefined reference to `pthread_create'"

add_executable(MainServer MainServer.cpp Server.cpp Controller.cpp DB_Connector.cpp)
target_link_libraries(MainServer mysqlcppconn) #убирает ошибку "undefined reference to `get_driver_instance'"