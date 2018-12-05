cmake_minimum_required(VERSION 3.12)
project(EE312proj8_Cheaters_exclamation_)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(.idea)
include_directories(cmake-build-debug)

add_executable(EE312proj8_Cheaters_exclamation_
        .idea/codeStyles/Project.xml
        .idea/.name
        .idea/EE312proj8_Cheaters-exclamation-.iml
        .idea/misc.xml
        .idea/modules.xml
        .idea/vcs.xml
        .idea/workspace.xml
        cmake-build-debug/cmake_install.cmake
        cmake-build-debug/EE312proj8_Cheaters_exclamation_.cbp
        cmake-build-debug/Makefile
        fileopen.cpp
        HashMap.h
        HashNode.h
        plagiarismChecker.cpp)
