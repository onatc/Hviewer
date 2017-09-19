cmake_minimum_required(VERSION 3.2)
project(P3 CXX)

enable_testing()
set(CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/deps/cxxtest)

find_package(CxxTest REQUIRED)
include_directories(${CXXTEST_INCLUDE_DIR})

CXXTEST_ADD_TEST(test_array_list test_dynamic_array_list.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/test_array_list.h abstract_list.h dynamic_array_list.h dynamic_array_list.txx )
set_property(TARGET test_array_list PROPERTY CXX_STANDARD 11)

CXXTEST_ADD_TEST(test_linked_list test_linked_list.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/test_linked_list.h abstract_list.h linked_list.h linked_list.txx )
set_property(TARGET test_linked_list PROPERTY CXX_STANDARD 11)

add_executable(hviewer hviewer.cpp abstract_list.h dynamic_array_list.h dynamic_array_list.txx linked_list.h linked_list.txx)
set_property(TARGET hviewer PROPERTY CXX_STANDARD 11)
