#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

#define SIZE 8
#define WINDOW_X 800
#define WINDOW_Y 800
using namespace std;
class ChessBoard {
    private:
        vector<sf::Sprite> squares;
        sf::Texture gray;
        sf::Texture brown;
        void generateSprite(int x, int y, string color);
    public:
        ChessBoard();
        void createwhole();
        void draw(sf::RenderWindow& window);
};