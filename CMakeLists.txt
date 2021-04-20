cmake_minimum_required(VERSION 3.1.0)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
	set(CMAKE_BUILD_TYPE "RelWithDebInfo")
endif()

project(XV11_RaspberryPi_Library LANGUAGES CXX)
include(GNUInstallDirs)
set(CMAKE_CXX_STANDARD 11)

add_compile_options(-Wall -Wconversion -Wextra -pedantic)

find_package (Threads)

set(LIBSRC xv11.cpp)
set(LIBINCLUDE xv11.h)

add_library(xv11
  STATIC
  ${LIBSRC}
  )

set_target_properties(xv11 PROPERTIES
  POSITION_INDEPENDENT_CODE TRUE
  PUBLIC_HEADER "${LIBINCLUDE}")

target_link_libraries(xv11 ${CMAKE_THREAD_LIBS_INIT} pigpio rt)

install(TARGETS xv11 EXPORT xv11_targets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

add_executable (printdata printdata.cpp)
target_link_libraries(printdata xv11)

add_executable (printRPM printRPM.cpp)
target_link_libraries(printRPM xv11)

add_executable (pwm pwm.cpp)
target_link_libraries(pwm pigpio rt ${CMAKE_THREAD_LIBS_INIT})
