include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)

FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

add_executable(test_program test_f.cpp ../src/f.cpp)

target_link_libraries(test_program gtest gtest_main)

target_include_directories(test_program PRIVATE ../include)

add_test(NAME lab1_test COMMAND test_program)