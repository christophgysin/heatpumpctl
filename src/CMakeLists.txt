set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR} PARENT_SCOPE)

add_executable(heatpumpctl heatpumpctl.cpp)
target_link_libraries(heatpumpctl
    ${LIB_SERIAL}
    ${Boost_SYSTEM_LIBRARY}
    ${Boost_THREAD_LIBRARY}
    ${CMAKE_THREAD_LIBS_INIT}
    )
