// player.hpp
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../../Library/SFML/include/SFML/Graphics.hpp"
#include "paddle.hpp"
#include "../InputSystem/inputSystem.hpp"

class Player
{
private:
    Paddle *paddle;              // Use a pointer for Paddle
    InputSystem *inputForPlayer; // use a pointer for Input system

public:
    int id;
    int score;

    Player(sf::Vector2f position, sf::Vector2f size, sf::Color color);

    void setInputKey(sf::Keyboard::Key firstKey, sf::Keyboard::Key secondKey);

    sf::Vector2f getPlayerPosistion(); // return a player(paddle positions)

    void setPlayerPositons(sf::Vector2f newPositions); // set a new postion to player

    Paddle *getPaddle()
    {
        return paddle;
    }

    void updatingInput(); /* Updateing input method is basically update a newPaddlePositon variable with new paddle postions */

    void draw(sf::RenderWindow &window);

    void deletePlayer();
};

#endif // PLAYER_HPP
