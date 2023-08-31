#ifndef USERINTERFACE_HPP
#define USERINTERFACE_HPP
#include <iostream>
#include <string>

#include "../../Library/SFML/include/SFML/Graphics.hpp"

using namespace sf;

class UserInterFace
{
public: /*Public Properties of userInterface */
    Font font;
    Color color;
    Vector2f position;
    int firstScore;
    int secondScore;
    int characterSize;

private: /*Public Properties of userInterface */
    Text mFirstScore;
    Text mSecondScore;
    Text mGameTimer;
    Text mGameStatus;
    Text mServerStatus;
    Text mClientStatus;
    sf::Texture m_scoreTexture;
    sf::Sprite m_scoreSprit;

public:
    /*Method of userInterFace Class*/
    UserInterFace();
    UserInterFace(int characterSize, Color color, Vector2f position);
    void drawFirstScore(sf::RenderWindow &window);
    void drawSecondScore(sf::RenderWindow &window);
    void drawGameStatus(sf::RenderWindow &window);
    void drawGameTimer(sf::RenderWindow &window);
    void drawScoreImage(sf::RenderWindow &window);
    void drawServerStatus(sf::RenderWindow &window);
    void drawClientStatus(sf::RenderWindow &window);

    void updateScore(int first_score, int second_score, const std::string &gameStatus, Color gameStatusColor);
};

#endif // USERINTERFACE_HPP