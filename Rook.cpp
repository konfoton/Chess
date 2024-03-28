#include "Rook.h"

Rook::Rook(Color color, sf::Texture &texture, int x, int y, float scale) : Piece(color, texture, x, y, scale) {}
void Rook::valid(vector<Piece*>& a, sf::Texture & texture, sf::RenderWindow& c){
    if(this->color == Color::White){
        int directions[] = {-1, 1};
        for(int i = 0; i < 2; i++){
            for(int j : directions){
                int x = posx();
                int y = posy();
                while(x < 800 && y < 800 && x > -100 && y > -100){
                    x += 100 * j * (i - 1);
                    y += 100 * j * i;
                    if(!check(x, y, a)){
                    createDraw(x, y, texture, c);
                    }
                    else {
                        break; 
                    }
                }
            }
        }
        for(int i = 0; i < 2; i++){
            for(int j : directions){
                int x = posx();
                int y = posy();
                while(x < 800 && y < 800 && x > -100 && y > -100){
                    x += 100 * j * (i - 1);
                    y += 100 * j * i;
                    if(checkc(x, y, a, Color::Black)){
                    createDraw(x, y, texture, c);
                    break;
                }
                if(check(x, y, a)){
                        break;
                    }
            }
        }
    }
}
if(this->color == Color::Black){
        int directions[] = {-1, 1};
        for(int i = 0; i < 2; i++){
            for(int j : directions){
                int x = posx();
                int y = posy();
                while(x < 800 && y < 800 && x > -100 && y > -100){
                    x += 100 * j * (i - 1);
                    y += 100 * j * i;
                    if(!check(x, y, a)){
                    createDraw(x, y, texture, c);
                    }
                    else {
                        break; 
                    }
                }
            }
        }
        for(int i = 0; i < 2; i++){
            for(int j : directions){
                int x = posx();
                int y = posy();
                while(x < 800 && y < 800 && x > -100 && y > -100){
                    x += 100 * j * (i - 1);
                    y += 100 * j * i;
                    if(checkc(x, y, a, Color::White)){
                    createDraw(x, y, texture, c);
                    break;
                } if(check(x, y, a)){
                        break;
                    }
            }
        }
    }
}
}