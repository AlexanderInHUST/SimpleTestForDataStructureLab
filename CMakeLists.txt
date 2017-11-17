cmake_minimum_required(VERSION 3.8)
project(StructureExprUnitTest)

set(GTEST_IDIR /Users/tangyifeng/googletest/googletest/include)
set(GTEST_LDIR /Users/tangyifeng/googletest/googletest/make)
set(GTEST_L ${GTEST_LDIR}/gtest-all.o)
include_directories(${GTEST_IDIR})
link_directories(${GTEST_LDIR})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_COMPILER g++)

set(SOURCE_FILES linked_list_unit_test.cpp linked_list_unit_test.h)
add_executable(StructureExprUnitTest ${SOURCE_FILES})

target_link_libraries(StructureExprUnitTest ${GTEST_L})