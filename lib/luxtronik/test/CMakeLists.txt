add_executable(parser_test parser_test.cpp)
target_link_libraries(parser_test luxtronik)
add_test(parser_test
    parser_test
        --log_level=all
        --log_format=xml
        --log_sink=unittest.log
        --report_level=detailed
        --report_sink=unittest.report
        --report_format=xml
    )
