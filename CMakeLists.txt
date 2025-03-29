cmake_minimum_required(VERSION 3.30)
project(Bank_Simulator)

set(CMAKE_CXX_STANDARD 20)

add_executable(Bank_Simulator src/main.cpp
        include/Account.h
        src/Account.cpp
        include/User.h
        src/User.cpp)
