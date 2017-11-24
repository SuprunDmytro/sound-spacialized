#!/bin/bash
g++ -c trySpSound.cpp
g++ trySpSound.o -o sfml-app -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

