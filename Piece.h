#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

#define SIZE 8
#define WINDOW_X 800
#define WINDOW_Y 800

using namespace std;

class Piece {
    public:
 
        enum class Color { White, Black };
        Piece(Color color, sf::Texture &texture, int x, int y, float scale);

        bool isClicked(int x, int y);

        virtual void valid(vector<Piece*>& a, sf::Texture & texture, sf::RenderWindow& c) = 0;
        virtual ~Piece();
        void draw(sf::RenderWindow& window);
        bool check(int x, int y, vector<Piece*>& a);
        int posx();
        int posy();
        void createDraw(int x, int y, sf::Texture &texture, sf::RenderWindow& c);
        bool checkc(int x, int y, vector<Piece*>& a, Color c);
        Color color;
        sf::Sprite sprite;
};