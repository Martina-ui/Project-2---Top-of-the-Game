#!/bin/bash
g++ -std=c++14 -I. -I./rapidjson/include $(curl-config --cflags) main.cpp $(curl-config --libs) -o game_program && ./game_program
