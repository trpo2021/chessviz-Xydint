cmake_minimum_required(VERSION 3.16)

project(Chess)

set(include_path "src/include")

#Build gtest
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/gtest"
"google test"
)

#Main target
add_executable(Chess.out
src/main.cpp
)

#Test target
add_executable(
test_list
test/test_list.cpp
)

#Build chessvizlib
add_library(chesslib 
src/Figure.cpp
src/ChessDesk.cpp
${include_path}/Figure.hpp
${include_path}/ChessDesk.hpp
)

#Adding main source to test target 
target_include_directories(
test_list PRIVATE 
"${CMAKE_CURRENT_SOURCE_DIR}/src"
)

#Add link to lib for test target
target_link_libraries(
test_list PRIVATE
gtest 
gtest_main 
chesslib
)

#Add link to lib for main target
target_link_libraries(
Chess.out
chesslib
)

#Add include dirs
include_directories(
${include_path}
gtest/googletest/include/gtest
)