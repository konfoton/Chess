#pragma once
#include "Piece.h"
class Rook : public Piece {
    public:
        Rook(Color color, sf::Texture &texture, int x, int y, float scale);
        void valid(vector<Piece*>& a, sf::Texture & texture, sf::RenderWindow& c) override;
};
