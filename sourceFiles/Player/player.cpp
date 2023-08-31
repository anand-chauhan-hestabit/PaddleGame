/*player.cpp file and implement a method of player.hpp */
#include "../../headerFiles/Player/player.hpp"

/*Implement  a constructor of Player and create a player*/
Player::Player(sf::Vector2f position, sf::Vector2f size, sf::Color color)
{
    score = 0;
    paddle = new Paddle(position, size, color); // Create a object of Paddle and set position,size and color
    inputForPlayer = new InputSystem(paddle);   // Send a paddle pointer to input-sytem to update a positions
}


/*Set a Input key for Player */
void Player::setInputKey(sf::Keyboard::Key firstKey, sf::Keyboard::Key secondKey)
{
    inputForPlayer->setKeys(firstKey, secondKey);
}


/*get Player player posistions */
sf::Vector2f Player::getPlayerPosistion()
{
    return inputForPlayer->newPaddlePositions;
}


/*implement a method for Update a position of Paddle*/
void Player::setPlayerPositons(sf::Vector2f newPositions)
{
    paddle->setPaddlePosition(newPositions);
}

void Player::updatingInput()
{
    inputForPlayer->updatingInputs();
    
}
/*implement a method for draw a Player(Paddle)*/
void Player::draw(sf::RenderWindow &window)
{
    paddle->drawPaddle(window);
}

void Player::deletePlayer()
{
    delete this->paddle;
}
// Player::getPaddle()
// {
//   return paddle->mpaddle;
// }