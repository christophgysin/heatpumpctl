set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR} PARENT_SCOPE)

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
