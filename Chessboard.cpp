#include "Chessboard.h"

void ChessBoard::generateSprite(int x, int y, string color){
        sf::Sprite sprite;
        if(color == "gray"){
        sprite.setTexture(gray);
        } else {
            sprite.setTexture(brown);
        }
        sprite.setTextureRect(sf::IntRect(0, 0, 100, 100));
        sprite.setPosition(x, y);
        squares.push_back(sprite);
        return;
        }   
ChessBoard::ChessBoard(){
            if(!gray.loadFromFile("graphics/gray.png")){
                    return;
            }
            if(!brown.loadFromFile("graphics/brown.png")){
                return;
            }
            createwhole();
        }
void ChessBoard::createwhole(){
            for(int i = 0; i < SIZE; i++){
                for(int j = 0; j < SIZE; j++){
                    if((i + j) % 2 == 1){
                    generateSprite(i * WINDOW_X / SIZE, j * WINDOW_Y / SIZE, "gray");
                } else {
                    generateSprite(i * WINDOW_X / SIZE, j * WINDOW_Y / SIZE, "brown");
                    }
            }
        }
        }
void ChessBoard::draw(sf::RenderWindow& window){
            for(sf::Sprite &a : squares){
                window.draw(a);
            }
        }