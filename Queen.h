#pragma once
#include "Piece.h"
class Queen : public Piece {
    public:
        Queen(Color color, sf::Texture &texture, int x, int y, float scale);
        void valid(vector<Piece*>& a, sf::Texture & texture, sf::RenderWindow& c) override;
};
