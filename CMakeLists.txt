cmake_minimum_required(VERSION 3.10)
project(PJ)

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS "-std=c++14 -O2")

include_directories(yourcode)

add_executable(main
        yourcode/submit-1AddPolygonBeforeQueryPoint.cpp
        yourcode/submit-1AddPolygonBeforeQueryPoint.h
        yourcode/submit-2AddPointBeforeQueryPolygon.cpp
        yourcode/submit-2AddPointBeforeQueryPolygon.h
        yourcode/submit-3AddBeforeQuery.cpp
        yourcode/submit-3AddBeforeQuery.h
        yourcode/submit-4MixQueryPoint.cpp
        yourcode/submit-4MixQueryPoint.h
        yourcode/submit-5MixQueryPolygon.cpp
        yourcode/submit-5MixQueryPolygon.h
        yourcode/submit-6MixQuery.cpp
        yourcode/submit-6MixQuery.h
        main.cpp)
