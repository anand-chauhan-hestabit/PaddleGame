#ifndef PADDLE_HPP
#define PADDLE_HPP
#include "../Library/SFML/include/SFML/Graphics.hpp"
using namespace sf;

class Paddle
{
public:
    Vector2f position;
    Vector2f velocity;
    Vector2f size;
    Color color;

    // private:
    RectangleShape mpaddle;

public:
    Paddle();
    /*
    Delaration of Paddle methods
    @param first-Arg set a position
    @param second-Arg set a size
    @param third-Arg set a Color
    */
    Paddle(Vector2f position, Vector2f size, Color color);

    void drawPaddle(sf::RenderWindow &window);

    void setUpdatePosition(sf::Vector2f position); /*Implment  a setter for mpaddle private membet of paddle*/
};

#endif // PADDLE_HPP