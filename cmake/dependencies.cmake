include(FindBoost)
set(BOOST_LIBS thread date_time system filesystem program_options)
find_package(Boost COMPONENTS ${BOOST_LIBS} REQUIRED)
find_package(Threads REQUIRED)
