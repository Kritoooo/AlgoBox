cmake_minimum_required(VERSION 3.28)
project(AlgoBox VERSION 1.0 DESCRIPTION "Algorithm and Data Structure Library using C++20 modules")

# 设置使用的 C++ 标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 指定使用 Clang++-17 作为编译器
set(CMAKE_CXX_COMPILER "clang++-17")

# 添加子目录
add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(example)
add_subdirectory(test)

# 可选：启用测试
enable_testing()
