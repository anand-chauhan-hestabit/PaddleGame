// inputsystem.hpp
#ifndef INPUTSYSTEM_H
#define INPUTSYSTEM_H
#include "../Library/SFML/include/SFML/Graphics.hpp"
#include "paddle.hpp"

class InputSystem
{
public:
    InputSystem(Paddle *paddle); /*Change the parameter to Paddle*/
    void setKeys(sf::Keyboard::Key firstKey, sf::Keyboard::Key secondKey);
    void update_paddle_position();

private:
    Paddle *paddle;                   // Change the member to Paddle*
    sf::Keyboard::Key firstInputKey;  // Key to move paddle up
    sf::Keyboard::Key secondInputKey; // Key to move paddle down
};

#endif // INPUTSYSTEM_H
