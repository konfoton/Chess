#include "King.h"

King::King(Color color, sf::Texture &texture, int x, int y, float scale) : Piece(color, texture, x, y, scale) {}
void King::valid(vector<Piece*>& a, sf::Texture & texture, sf::RenderWindow& c){
    if (this->color == Piece::Color::Black) {
    int directions[] = {-1, 0, 1};
    for (int dx : directions) {
        for (int dy : directions) {
            if (dx == 0 && dy == 0)
                continue;
            int x = posx() + dx * 100;
            int y = posy() + dy * 100;
            if (!check(x, y, a)) {
                createDraw(x, y, texture, c);
            }
        }
    }
    for (int dx : directions) {
        for (int dy : directions) {
            if (dx == 0 && dy == 0)
                continue;
            int x = posx() + dx * 100;
            int y = posy() + dy * 100;
            if (checkc(x, y, a, Color::White)) {
                createDraw(x, y, texture, c);
            }
        }
    }
}
if (this->color == Piece::Color::White) {
    int directions[] = {-1, 0, 1};
    for (int dx : directions) {
        for (int dy : directions) {
            if (dx == 0 && dy == 0)
                continue;
            int x = posx() + dx * 100;
            int y = posy() + dy * 100;
            if (!check(x, y, a)) {
                createDraw(x, y, texture, c);
            }
        }
    }
    for (int dx : directions) {
        for (int dy : directions) {
            if (dx == 0 && dy == 0)
                continue;
            int x = posx() + dx * 100;
            int y = posy() + dy * 100;
            if (checkc(x, y, a, Color::Black)) {
                createDraw(x, y, texture, c);
            }
        }
    }
}
}
