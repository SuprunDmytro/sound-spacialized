#!/bin/bash
g++ -c trySpSound.cpp
g++ trySpSound.o -o sfml-app -lsfml-audio -lsfml-graphics -lsfml-system

