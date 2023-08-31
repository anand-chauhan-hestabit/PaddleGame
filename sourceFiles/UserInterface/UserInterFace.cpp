/*UserInterFace.cpp file */
#include "../../headerFiles/UserInterface/UserInterFace.hpp"
#include <iostream>
using namespace std;

/* Implement a constructor of UserInterface */
UserInterFace::UserInterFace(int characterSize, Color color, Vector2f position)
{

    if (!font.loadFromFile("assets/fonts/english.ttf"))
    {
        std::cout << "Failed to load font." << std::endl;
    }

    if (!m_scoreTexture.loadFromFile("assets/pictures/score.png"))
    {
        std::cout << "Failed to load images. " << std::endl;
    }

    /*Set the values for all UserInterface  properties*/
    this->characterSize = characterSize;
    this->color = color;
    this->position = position;
    this->font = font;

    /*Load and draw a image of socre texture */
    m_scoreSprit.setTexture(m_scoreTexture);
    m_scoreSprit.setPosition(this->position.x / 2 - m_scoreTexture.getSize().x / 2, this->position.y * 0 + 20);

    /* Set all properties of mFirstScore for display on screen and also implement a draw methods*/

    mFirstScore.setFont(this->font);
    mFirstScore.setCharacterSize(this->characterSize);
    mFirstScore.setFillColor(this->color);
    mFirstScore.setPosition(this->position.x / 4, this->position.y / 25);
    mFirstScore.setString("100");

    /* Set all properties of mSecondScore for display on screen and also implement a draw methods*/

    mSecondScore.setFont(this->font);
    mSecondScore.setCharacterSize(this->characterSize);
    mSecondScore.setFillColor(this->color);
    mSecondScore.setPosition(this->position.x / 1.25, this->position.y / 25);
    mSecondScore.setString("100");

    /* Set all properties of mGameStatus for display on screen and also implement a draw methods*/

    mGameStatus.setFont(this->font);
    mGameStatus.setCharacterSize(this->characterSize);
    mGameStatus.setFillColor(this->color);
    mGameStatus.setPosition(this->position.x / 1.15, this->position.y / 40);
    mGameStatus.setString("");

    /*set all properties for show the server status */
    mServerStatus.setFont(this->font);
    mServerStatus.setCharacterSize(this->characterSize);
    mServerStatus.setFillColor(this->color);
    mServerStatus.setPosition(this->position.x / 7, this->position.y / 25);
    mServerStatus.setString("server");

    /*set all properties for show the client status */

    mClientStatus.setFont(this->font);
    mClientStatus.setCharacterSize(this->characterSize);
    mClientStatus.setFillColor(this->color);
    mClientStatus.setPosition(this->position.x / 1.42, this->position.y / 25);
    mClientStatus.setString("client");
}

/* Implement a method for a updateScore During running game*/
void UserInterFace::updateScore(int first_score, int second_score, const std::string &gameStatus, Color gameStatusColor)
{
    mFirstScore.setString(std::to_string(first_score));
    mSecondScore.setString(std::to_string(second_score));
    mGameStatus.setString(gameStatus);
    mGameStatus.setFillColor(gameStatusColor);
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

void UserInterFace::drawScoreImage(sf::RenderWindow &window)
{
    window.draw(this->m_scoreSprit);
}

void UserInterFace::drawServerStatus(sf::RenderWindow &window)
{
    window.draw(this->mServerStatus);
}

void UserInterFace::drawClientStatus(sf::RenderWindow &window)
{
    window.draw(this->mClientStatus);
}