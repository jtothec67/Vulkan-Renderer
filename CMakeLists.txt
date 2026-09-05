cmake_minimum_required(VERSION 4.2)

project(VulkanRenderer LANGUAGES CXX)

add_executable(VulkanRenderer
    src/main.cpp
)

target_compile_features(VulkanRenderer PRIVATE cxx_std_23)