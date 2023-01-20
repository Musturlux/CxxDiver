cmake_minimum_required(VERSION 3.16)

project(
    codeEntrainement
)

include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.2.0 # or a later release
)

FetchContent_MakeAvailable(Catch2)


add_executable(check_parenthese)
target_sources(check_parenthese PRIVATE src/main.cpp 
                                        src/parenthese.cpp 
)
target_compile_features(check_parenthese PRIVATE cxx_std_20)

target_compile_options(check_parenthese PRIVATE -Wall -Wswitch_enum)

add_executable(check_parenthese_test)
target_sources(check_parenthese_test PRIVATE test/check_parenthese_test.cpp src/parenthese.cpp src/parenthese.hpp) 
target_compile_features(check_parenthese_test PRIVATE cxx_std_20)

target_link_libraries(check_parenthese_test PRIVATE Catch2::Catch2WithMain)

target_include_directories(check_parenthese_test PRIVATE src)