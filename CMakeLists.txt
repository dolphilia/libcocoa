cmake_minimum_required(VERSION 3.16)
project(libcocoa 
    VERSION 1.0.0
    DESCRIPTION "C wrapper library for macOS Cocoa frameworks"
    LANGUAGES C
)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

if(NOT APPLE)
    message(FATAL_ERROR "libcocoa requires macOS")
endif()

set(CMAKE_C_FLAGS_DEBUG "-g -O0 -Wall -Wextra")
set(CMAKE_C_FLAGS_RELEASE "-O3 -DNDEBUG")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)


add_subdirectory(src)

option(BUILD_EXAMPLES "Build example programs" ON)
if(BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

option(BUILD_TESTS "Build test programs" OFF)
if(BUILD_TESTS)
    add_subdirectory(tests)
    enable_testing()
endif()

set_target_properties(libcocoa PROPERTIES
    PUBLIC_HEADER "include/libcocoa/libcocoa.h"
)

include(GNUInstallDirs)

install(TARGETS libcocoa
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/libcocoa
)

install(DIRECTORY include/libcocoa
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    FILES_MATCHING PATTERN "*.h"
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)