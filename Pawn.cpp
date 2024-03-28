#include "Pawn.h"

Pawn::Pawn(Color color, sf::Texture &texture, int x, int y, float scale) : Piece(color, texture, x, y, scale) {}
void Pawn::valid(vector<Piece*>& a, sf::Texture & texture, sf::RenderWindow& c){
    sf::Sprite temp1;
    sf::Sprite temp2;
    if(this->color == Piece::Color::White){
        if(this->sprite.getPosition().y == 600 && !check(posx(), posy() - 200, a) &&
        !check(posx(), posy()-100, a)){
           createDraw(posx(), posy() - 100, texture, c);
           createDraw(posx(), posy() - 200, texture, c);
        }
        if(!check(posx(), posy() - 100, a)){
            createDraw(posx(), posy() - 100, texture, c);
        }
        if(checkc(posx() - 100 , posy() - 100, a, Color::Black)){
            createDraw(posx() - 100, posy() - 100, texture, c);
        }
        if(checkc(posx() + 100 , posy() - 100, a, Color::Black)){
            createDraw(posx() + 100, posy() - 100, texture, c);
        }

    }
    if(this->color == Piece::Color::Black){
    if(this->sprite.getPosition().y == 100 && !check(posx(), posy() + 200, a) &&
       !check(posx(), posy() + 100, a)){
           createDraw(posx(), posy() + 100, texture, c);
           createDraw(posx(), posy() + 200, texture, c);
    }
    if(!check(posx(), posy() + 100, a)){
        createDraw(posx(), posy() + 100, texture, c);
    }
    if(checkc(posx() - 100 , posy() + 100, a, Color::White)){
        createDraw(posx() - 100, posy() + 100, texture, c);
    }
    if(checkc(posx() + 100 , posy() + 100, a, Color::White)){
        createDraw(posx() + 100, posy() + 100, texture, c);
    }
}

}
