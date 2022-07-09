#!/bin/bash

rm -rf build && mkdir build && cd build && cmake .. && make && ./NBody -CPU=1