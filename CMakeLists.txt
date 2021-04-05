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
  SHARED
  ${LIBSRC}
  )

set_target_properties(xv11 PROPERTIES
  SOVERSION 1
  PUBLIC_HEADER "${LIBINCLUDE}")

target_link_libraries(xv11 ${CMAKE_THREAD_LIBS_INIT} pigpiod_if2 rt)

install(TARGETS xv11 EXPORT xv11-targets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

add_library(xv11_static
  STATIC
  ${LIBSRC}
  )

set_target_properties(xv11_static PROPERTIES
  PUBLIC_HEADER "${LIBINCLUDE}")

target_link_libraries(xv11_static ${CMAKE_THREAD_LIBS_INIT} pigpiod_if2 rt)

install(TARGETS xv11_static EXPORT xv11_static-targets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

add_executable (printdata printdata.cpp)
target_link_libraries(printdata xv11_static)

add_executable (printRPM printRPM.cpp)
target_link_libraries(printRPM xv11_static)

add_executable (pwm pwm.cpp)
target_link_libraries(pwm pigpiod_if2 rt)
