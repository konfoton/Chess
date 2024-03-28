#include "Knight.h"

Knight::Knight(Color color, sf::Texture &texture, int x, int y, float scale) : Piece(color, texture, x, y, scale) {}
void Knight::valid(vector<Piece*>& a, sf::Texture & texture, sf::RenderWindow& c){
    if(this->color == Color::White){
        int directions[] = {1, -1};
        int values[] = {200, 100};
        for(int i = 0; i < 2; i++){
            for(int j : directions){
                for(int k : directions){
                    if(!check(posx() + j * values[i % 2], posy() + k * values[(i + 1) % 2], a)){
                        createDraw(posx() + j * values[i % 2], posy() + k * values[(i + 1) % 2], texture, c);
                        }
                }
            }
        }
        for(int i = 0; i < 2; i++){
            for(int j : directions){
                for(int k : directions){
                    if(checkc(posx() + j * values[i % 2], posy() + k * values[(i + 1) % 2], a, Color::Black)){
                        createDraw(posx() + j * values[i % 2], posy() + k * values[(i + 1) % 2], texture, c);
                        }
                }
            }
        }
    
}
if(this->color == Color::Black){
        int directions[] = {1, -1};
        int values[] = {200, 100};
        for(int i = 0; i < 2; i++){
            for(int j : directions){
                for(int k : directions){
                    if(!check(posx() + j * values[i % 2], posy() + k * values[(i + 1) % 2], a)){
                        createDraw(posx() + j * values[i % 2], posy() + k * values[(i + 1) % 2], texture, c);
                        }
                }
            }
        }
        for(int i = 0; i < 2; i++){
            for(int j : directions){
                for(int k : directions){
                    if(checkc(posx() + j * values[i % 2], posy() + k * values[(i + 1) % 2], a, Color::White)){
                        createDraw(posx() + j * values[i % 2], posy() + k * values[(i + 1) % 2], texture, c);
                        }
                }
            }
        }
    
}

}
