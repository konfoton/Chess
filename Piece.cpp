#include "Piece.h"

Piece::Piece(Color color, sf::Texture &texture, int x, int y, float scale) : color(color) {
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
    sprite.setScale(scale , scale);
}

bool Piece::isClicked(int x, int y){
if(((x / 100) * 100 == sprite.getPosition().x) && ((y/100) * 100 == sprite.getPosition().y)){
    return true;
}
return false;
}
void Piece::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}
bool Piece::check(int x, int y, vector<Piece*>& a){
    for(int i = 0; i < a.size(); i++){
        if(a[i]->sprite.getPosition().x == x && a[i]->sprite.getPosition().y == y){
            return true; 
        }
    }
    return false;
}
bool Piece::checkc(int x, int y, vector<Piece*>& a, Color c){
    for(int i = 0; i < a.size(); i++){
        if(a[i]->sprite.getPosition().x == x && a[i]->sprite.getPosition().y == y && a[i]->color == c){
            return true; 
        }
    }
    return false;
}
int Piece::posx(){
    return this->sprite.getPosition().x;
}
int Piece::posy(){
    return this->sprite.getPosition().y;
}
Piece::~Piece(){}
void Piece::createDraw(int x, int y, sf::Texture &texture, sf::RenderWindow& c){
    sf::Sprite temp1;
    temp1.setPosition(x, y);
    temp1.setTexture(texture);
    c.draw(temp1);
}