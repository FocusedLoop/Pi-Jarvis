cmake_minimum_required(VERSION 3.10)
project(TestProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(fmt REQUIRED)
find_package(CURL REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(PkgConfig REQUIRED)

pkg_check_modules(GTKMM REQUIRED gtkmm-4.0)
pkg_check_modules(JSONCPP REQUIRED jsoncpp)
pkg_check_modules(LIBSSH REQUIRED libssh)

add_executable(test 
    src/main.cpp
    src/CommandMapping.cpp
    src/ToggleWidget.cpp
    src/Button.cpp
    src/MainWindow.cpp
    src/DeviceWidget.cpp
    
 "src/ConnectionState.cpp" "include/ConnectionState.h")

include_directories(include)

find_path(LIBSSH_INCLUDE_DIR
    NAMES libssh.h
    PATH_SUFFIXES libssh
    PATHS /usr/include /usr/local/include
)
target_include_directories(test PRIVATE
    ${GTKMM_INCLUDE_DIRS}
    ${JSONCPP_INCLUDE_DIRS}
)

target_link_directories(test PRIVATE
    ${GTKMM_LIBRARY_DIRS}
    ${JSONCPP_LIBRARY_DIRS}
    ${LIBSSH_LIBRARY_DIRS}
)
target_compile_options(test PRIVATE
    ${GTKMM_CFLAGS_OTHER}
    ${JSONCPP_CFLAGS_OTHER}
)
target_link_options(test PRIVATE
    ${GTKMM_LDFLAGS_OTHER}
    ${JSONCPP_LDFLAGS_OTHER}
)

target_link_libraries(test PRIVATE
    fmt::fmt
    CURL::libcurl
    OpenSSL::SSL
    ${GTKMM_LIBRARIES}
    ${JSONCPP_LIBRARIES}
    ${LIBSSH_LIBRARIES}
)

configure_file(${CMAKE_SOURCE_DIR}/commands.json ${CMAKE_BINARY_DIR}/commands.json COPYONLY)