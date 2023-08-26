/*UserInterFace.cpp file */
#include "../headerFiles/UserInterFace.hpp"
#include <iostream>
using namespace std;

/* Implement a constructor of UserInterface */
UserInterFace::UserInterFace(int characterSize, Color color, Vector2f position)
{
    Font font;
    if (!font.loadFromFile("/home/hestabit/Desktop/PaddleGame/assets/fonts/english.ttf"))
    {
        std::cout << "Failed to load font." << std::endl;
    }

    /*Set the values for all UserInterface  properties*/
    this->characterSize = characterSize;
    this->color = color;
    this->position = position;
    this->font = font;

    /* Set all properties of mFirstScore for display on screen and also implement a draw methods*/

    mFirstScore.setFont(this->font);
    mFirstScore.setCharacterSize(this->characterSize);
    mFirstScore.setFillColor(this->color);
    mFirstScore.setPosition(this->position.x / 4, this->position.y / 15);
    mFirstScore.setString("100");

    /* Set all properties of mSecondScore for display on screen and also implement a draw methods*/

    mSecondScore.setFont(this->font);
    mSecondScore.setCharacterSize(this->characterSize);
    mSecondScore.setFillColor(this->color);
    mSecondScore.setPosition(this->position.x / 1.33, this->position.y / 15);
    mSecondScore.setString("100");

    /* Set all properties of mGameStatus for display on screen and also implement a draw methods*/

    mGameStatus.setFont(this->font);
    mGameStatus.setCharacterSize(this->characterSize / 1.5);
    mGameStatus.setFillColor(this->color);
    mGameStatus.setPosition(this->position.x / 1.066, this->position.y / 20);
    mGameStatus.setString("");
}

/* Implement a method for a updateScore During running game*/
void UserInterFace::updateScore(int first_score, int second_score,const std::string& gameStatus)
{
    mFirstScore.setString(std::to_string(first_score));
    mSecondScore.setString(std::to_string(second_score));
    mGameStatus.setString(gameStatus);

}

/*
method definition for drawFirstScore
*/
void UserInterFace::drawFirstScore(sf::RenderWindow &window)
{
    window.draw(this->mFirstScore);
}

/*
method definition for drawSecondScore
*/
void UserInterFace::drawSecondScore(sf::RenderWindow &window)
{
    window.draw(this->mSecondScore);
}

/*
method definition for drawGameStatus
*/
void UserInterFace::drawGameStatus(sf::RenderWindow &window)
{
    window.draw(this->mGameStatus);
}