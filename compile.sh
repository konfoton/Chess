#!/bin/bash
g++ -std=c++11 main.cpp Chessboard.cpp Piece.cpp Pawn.cpp Bishop.cpp King.cpp Knight.cpp Rook.cpp Queen.cpp -o final -I include -L lib -l sfml-system -l sfml-window -l sfml-graphics -l sfml-audio -l sfml-network -Wl,-rpath ./lib
./final
