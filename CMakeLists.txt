# cmake_minimum_required(VERSION 3.3)
project(mafn_ate)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread" )

include_directories(${CMAKE_SOURCE_DIR})

set(SOURCE_FILES
    ATE_BlockQueue/block.cpp
    ATE_BlockQueue/block.h
    ATE_BlockQueue/blockqueue.cpp
    ATE_BlockQueue/blockqueue.h
    blockqueuefiller.cpp
    blockqueuefiller.h
    coefficients.cpp
    coefficients.h
    main.cpp
    options.cpp
    options.h
    OS_namespaces.h ThreadManager.cpp ThreadManager.hpp config.hpp ThreadWorker.cpp ThreadWorker.hpp)

find_package (Threads)
add_executable(mafn_ate ${SOURCE_FILES})
target_link_libraries (mafn_ate ${CMAKE_THREAD_LIBS_INIT})