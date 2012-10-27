include_directories(.)
add_subdirectory(test)

set(SRCS
    heatpumpctl.cpp
    )
add_executable(heatpumpctl
    ${SRCS}
    )
target_link_libraries(heatpumpctl
    ${Boost_SYSTEM_LIBRARY}
    pthread
    )
