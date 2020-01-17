#!/bin/bash

rm -rf Build
mkdir Build
cd Build
cmake ..
make
cd ..
Build/AP_Project
