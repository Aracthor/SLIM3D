#!/bin/sh

mkdir build
mkdir build/release
mkdir build/debug
cd build/release
cmake -DCMAKE_BUILD_TYPE=Release ../..
cd ../../
cd build/debug
cmake -DCMAKE_BUILD_TYPE=Debug ../..
