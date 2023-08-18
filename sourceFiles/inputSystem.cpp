/*inputSystem.cpp implementing  a method of inputSystem.hpp*/
#include "../headerFiles/inputSystem.hpp"

#include <iostream>
using namespace std;

/*Implement a constructor for set a paddle pointer*/
InputSystem::InputSystem(Paddle *paddle) : paddle(paddle)
{
            this->newPaddlePositions = paddle->position;
}

/*Implement a setKeys method for set a input button for paddle*/
void InputSystem::setKeys(sf::Keyboard::Key firstKey, sf::Keyboard::Key secondKey)
{

    this->firstInputKey = firstKey;   /*Set first key for player(paddle control)*/
    this->secondInputKey = secondKey; /*Set a second key for player (paddle Control)*/
}

void InputSystem::update_paddle_position() /*Upading a paddle with input keys */
{

    if (sf::Keyboard::isKeyPressed(this->firstInputKey))
    {
        // this->newPaddlePositions = paddle->position;
        this->newPaddlePositions.y -= 15.0f; // Modify the position (e.g., move the paddle up)
        cout<<newPaddlePositions.y<< "minus input system called methods"<<endl;

        // Check if the new position is above the top of the screen
        if (newPaddlePositions.y < 0)
        {
            newPaddlePositions.y = 0; // Clamp the position to the top of the screen
        }

        // paddle->setUpdatePosition(newPaddlePositions); // Set the new position using the public method
    }

    if (sf::Keyboard::isKeyPressed(this->secondInputKey))
    {
        // this->newPaddlePositions = paddle->position;
        this->newPaddlePositions.y += 15.0f; // Modify the position (e.g., move the paddle down)

        // Check if the bottom of the paddle is below the bottom of the screen
        if (newPaddlePositions.y + paddle->size.y >= sf::VideoMode::getDesktopMode().height)
        {
            newPaddlePositions.y = sf::VideoMode::getDesktopMode().height - paddle->size.y;
        }

        // std::cout << this->newPaddlePositions.y << "\n";
                cout<<newPaddlePositions.y <<" plus input system called methods"<<endl;


        // paddle->setUpdatePosition(newPaddlePositions); // Set the updated position of the paddle with the setter
    }
}
