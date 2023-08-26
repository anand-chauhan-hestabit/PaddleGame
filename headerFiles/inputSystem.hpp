// inputsystem.hpp
#ifndef INPUTSYSTEM_H
#define INPUTSYSTEM_H
#include "../Library/SFML/include/SFML/Graphics.hpp"
#include "paddle.hpp"
#include "client.hpp"

class InputSystem
{
public:
    InputSystem(Paddle *paddle); /*sending a paddle pointer to input system for some calculatiosn like(paddle boundy set) */

    void setKeys(sf::Keyboard::Key firstKey, sf::Keyboard::Key secondKey);
    
    void updatingInputs(); // updating a inputs keys and new values

    sf::Vector2f newPaddlePositions; // New PaddlePostion for player (but now not set)

private:
    Paddle *paddle;
    // Change the member to Paddle*
    sf::Keyboard::Key firstInputKey;  // Key to move paddle up
    sf::Keyboard::Key secondInputKey; // Key to move paddle down
};

#endif // INPUTSYSTEM_H
