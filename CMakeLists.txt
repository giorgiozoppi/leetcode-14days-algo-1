cmake_minimum_required(VERSION 3.14)
project(challanges)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
add_executable(rotate_array ${CMAKE_CURRENT_SOURCE_DIR}/rotate_array/rotate_array.cpp)
add_executable(search ${CMAKE_CURRENT_SOURCE_DIR}/search/search.cpp)
add_executable(move_zeros ${CMAKE_CURRENT_SOURCE_DIR}/move_zeros/move_zeros.cpp)
add_executable(listnode_iterator ${CMAKE_CURRENT_SOURCE_DIR}/listnode_iterator/linkedlist.h  
                                 ${CMAKE_CURRENT_SOURCE_DIR}/listnode_iterator/main.cpp)



