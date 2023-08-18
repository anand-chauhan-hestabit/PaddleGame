// player.hpp
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../Library/SFML/include/SFML/Graphics.hpp"
#include "paddle.hpp"
#include "inputSystem.hpp"

class Player
{
private:
    Paddle *paddle;     // Use a pointer for Paddle
    InputSystem *input; // use a pointer for Input system

public:
    int id;
    int score;
    Player(sf::Vector2f position, sf::Vector2f size, sf::Color color);
    void setInputKey(sf::Keyboard::Key firstKey, sf::Keyboard::Key secondKey);
    void updatePostion();

    Paddle* getPaddle()
    {
        return paddle; // Return the Paddle object by reference //return a paddlle for get a bounds of paddle for collisions and this is getter for private membet 
    }
     InputSystem* getInput()
    {
        return input; // Return the Paddle object by reference //return a paddlle for get a bounds of paddle for collisions and this is getter for private membet 
    }

    void draw(sf::RenderWindow &window);
};

#endif // PLAYER_HPP
