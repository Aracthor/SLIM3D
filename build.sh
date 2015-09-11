#!/bin/sh
## build.sh for SLIM3D in /home/aracthor/programs/projects/SLIM3D
## 
## Made by Aracthor
## 
## Started on  Fri Sep 11 21:37:48 2015 Aracthor
## Last Update Fri Sep 11 21:38:45 2015 Aracthor
##

mkdir build
mkdir build/release
mkdir build/debug
cd build/release
cmake -DCMAKE_BUILD_TYPE=Release ../..
cd ../../
cd build/debug
cmake -DCMAKE_BUILD_TYPE=Debug ../..
