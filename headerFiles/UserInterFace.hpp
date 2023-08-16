#ifndef USERINTERFACE_HPP
#define USERINTERFACE_HPP

#include "../Library/SFML/include/SFML/Graphics.hpp"

using namespace sf;

class UserInterFace
{
public:             /*Public Properties of userInterface */
    Font font;
    Color color;
    Vector2f position;
    int firstScore;
    int secondScore;
    int characterSize;

private:            /*Public Properties of userInterface */
    Text mFirstScore;
    Text mSecondScore;
    Text mGameTimer;
    Text mGameStatus;

public:
    /*Method of userInterFace Class*/
    UserInterFace();
    UserInterFace(int characterSize, Color color, Vector2f position);
    void drawFirstScore(sf::RenderWindow &window);
    void drawSecondScore(sf::RenderWindow &window);
    void drawGameStatus(sf::RenderWindow &window);
    void drawGameTimer(sf::RenderWindow &window);
    void updateScore(int first_score,int second_score);
};

#endif // USERINTERFACE_HPP