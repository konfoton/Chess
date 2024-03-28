#include "Chessboard.h"
#include "Piece.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "King.h"
#include "Queen.h"
int main(){
    sf::RenderWindow window(sf::VideoMode(WINDOW_X, WINDOW_Y), "CHESS");

    ChessBoard board;

    sf::Texture* pawnWhite = new sf::Texture();

    sf::Texture* bishopWhite = new sf::Texture();

    sf::Texture* kingWhite = new sf::Texture();

    sf::Texture* queenWhite = new sf::Texture();

    sf::Texture* rookWhite = new sf::Texture();

    sf::Texture* knightWhite = new sf::Texture();

    sf::Texture* pawnBlack = new sf::Texture();

    sf::Texture* bishopBlack = new sf::Texture();

    sf::Texture* kingBlack = new sf::Texture();

    sf::Texture* queenBlack = new sf::Texture();

    sf::Texture* knightBlack = new sf::Texture();

    sf::Texture* rookBlack = new sf::Texture();

    sf::Texture* every = new sf::Texture();

    vector<Piece*> all;

    sf::Clock clock;

    if(!pawnWhite->loadFromFile("graphics/white-pawn.png")){
        return -1;
    }

    if(!bishopWhite->loadFromFile("graphics/white-bishop.png")){
        return -1;
    }

    if(!kingWhite->loadFromFile("graphics/white-king.png")){
        return -1;
    }

    if(!queenWhite->loadFromFile("graphics/white-queen.png")){
        return -1;
    }

    if(!rookWhite->loadFromFile("graphics/white-rook.png")){
        return -1;
    }

    if(!knightWhite->loadFromFile("graphics/white-knight.png")){
        return -1;
    }

    if(!pawnBlack->loadFromFile("graphics/black-pawn.png")){
        return -1;
    }

    if(!bishopBlack->loadFromFile("graphics/black-bishop.png")){
        return -1;
    }

    if(!kingBlack->loadFromFile("graphics/black-king.png")){
        return -1;
    }

    if(!queenBlack->loadFromFile("graphics/black-queen.png")){
        return -1;
    }

    if(!rookBlack->loadFromFile("graphics/black-rook.png")){
        return -1;
    }

    if(!knightBlack->loadFromFile("graphics/black-knight.png")){
        return -1;
    }

    if(!every->loadFromFile("graphics/valid.png")){
        return -1;
    }

    // creating white pawns
    for(int i = 0; i < 8; i++){
        Piece* temp = new Pawn(Piece::Color::White, *pawnWhite, i * 100, 600, 100.f/128.f);
        all.push_back(temp);
    }
    // creating black pawns
    for(int i = 0; i < 8; i++){
        Piece* temp = new Pawn(Piece::Color::Black, *pawnBlack, i * 100, 100, 100.f/128.f);
        all.push_back(temp);
    }
    Piece* temp = new Rook(Piece::Color::White, *rookWhite, 0, 700, 100.f/128.f);
    all.push_back(temp);
    
    temp = new Rook(Piece::Color::White, *rookWhite, 700, 700, 100.f/128.f);
    all.push_back(temp);
    
    temp = new Knight(Piece::Color::White, *knightWhite, 600, 700, 100.f/128.f);
    all.push_back(temp);

    temp = new Knight(Piece::Color::White, *knightWhite, 100, 700, 100.f/128.f);
    all.push_back(temp);

    temp = new Bishop(Piece::Color::White, *bishopWhite, 200, 700, 100.f/128.f);
    all.push_back(temp);

    temp = new Bishop(Piece::Color::White, *bishopWhite, 500, 700, 100.f/128.f);
    all.push_back(temp);

    temp = new Queen(Piece::Color::White, *queenWhite, 300, 700, 100.f/128.f);
    all.push_back(temp);

    temp = new King(Piece::Color::White, *kingWhite, 400, 700, 100.f/128.f);
    all.push_back(temp);

    temp = new Rook(Piece::Color::Black, *rookBlack, 0, 0, 100.f/128.f);
    all.push_back(temp);

    temp = new Rook(Piece::Color::Black, *rookBlack, 700, 0, 100.f/128.f);
    all.push_back(temp);

    temp = new Bishop(Piece::Color::Black, *bishopBlack, 200, 0, 100.f/128.f);
    all.push_back(temp);

    temp = new Bishop(Piece::Color::Black, *bishopBlack, 500, 0, 100.f/128.f);
    all.push_back(temp);

    temp = new Knight(Piece::Color::Black, *knightBlack, 600, 0, 100.f/128.f);
    all.push_back(temp);

    temp = new Knight(Piece::Color::Black, *knightBlack, 100, 0, 100.f/128.f);
    all.push_back(temp);

    temp = new Queen(Piece::Color::Black, *queenBlack, 300, 0, 100.f/128.f);
    all.push_back(temp);

    temp = new King(Piece::Color::Black, *kingBlack, 400, 0, 100.f/128.f);
    all.push_back(temp);

    Piece* last;

    int index;
    bool chosen = false; 


    while(window.isOpen()){

        // Event loop

        sf::Event event;

        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
            window.close();
        }
    }

    //managing all piecies logic

    if(clock.getElapsedTime().asSeconds() > 0.5f){
        for(int i = 0; i < all.size(); i++){
            if(!chosen){
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    if((*all[i]).isClicked(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)){
                        last = all[i];
                        index = i;
                        chosen = true;
                        clock.restart();
                    }
                }
            } else {
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && index == i){
                    
                    chosen = false;
                    int x = (sf::Mouse::getPosition(window).x/ 100) * 100;
                    int y = (sf::Mouse::getPosition(window).y/100) * 100;
                    for(int i = 0; i < all.size(); i++){
                        if((*all[i]).isClicked(x, y)){
                            delete all[i];
                            all.erase(all.begin() + i);
                    }
                    }
                    (last->sprite).setPosition(x, y);
                    last = nullptr;
                    clock.restart();
            }
            }
        }
    }


    window.clear();

    board.draw(window);
    for(int i = 0; i < all.size(); i++){
        (*all[i]).draw(window);
        if(last){
            last->valid(all, *every, window);
        }
    }

    window.display();

}
for(int i = 0; i < all.size(); i++){
        delete all[i];
    }
delete pawnWhite;
delete bishopWhite;
delete kingWhite;
delete queenWhite;
delete rookWhite;
delete knightWhite;
delete pawnBlack;
delete bishopBlack;
delete kingBlack;
delete queenBlack;
delete knightBlack;
delete rookBlack;
delete every;
return 0; 
}
