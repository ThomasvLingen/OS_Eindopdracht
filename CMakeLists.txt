# cmake_minimum_required(VERSION 3.3)
project(mafn_ate)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread" )

set(SOURCE_FILES
    block.cpp
    block.h
    blockqueue.cpp
    blockqueue.h
    blockqueuefiller.cpp
    blockqueuefiller.h
    coefficients.cpp
    coefficients.h
    main.cpp
    options.cpp
    options.h
    OS_namespaces.h ThreadManager.cpp ThreadManager.hpp config.hpp)

find_package (Threads)
add_executable(mafn_ate ${SOURCE_FILES})
target_link_libraries (mafn_ate ${CMAKE_THREAD_LIBS_INIT})