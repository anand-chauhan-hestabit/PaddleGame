/*player.cpp file and implement a method of player.hpp */
#include "../headerFiles/player.hpp"
#include <SFML/Graphics.hpp>

/*Implement  a constructor of Player and create a player*/
Player::Player(sf::Vector2f position, sf::Vector2f size, sf::Color color)
{
    score = 0;
    paddle = new Paddle(position, size, color); // Create a object of Paddle and set position,size and color
    input = new InputSystem(paddle);
}

/*Set a Input key for Player */
void Player::setInputKey(sf::Keyboard::Key firstKey, sf::Keyboard::Key secondKey)
{
    input->setKeys(firstKey, secondKey);
}

/*implement a method for Update a position of Paddle*/
void Player::updatePostion()
{
    input->update_paddle_position();
}

/*implement a method for draw a Player(Paddle)*/
void Player::draw(sf::RenderWindow &window)
{
    paddle->drawPaddle(window);
}
