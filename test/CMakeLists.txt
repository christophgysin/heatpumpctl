include_directories(${SRC_DIR})
add_executable(parser_test
    ${SRC_DIR}/Parser.cpp
    parser_test.cpp)
add_test(parser_test parser_test)
