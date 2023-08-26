/*paddle.cpp file implement a method of paddle.hpp*/
#include "../headerFiles/paddle.hpp"

/*Implement constructor for create a Paddle
@param first-Arg set a paddle-position
@param second-Arg set a paddle-position
@param third-Arg set a color of paddle
 */

Paddle::Paddle(Vector2f position, Vector2f size, Color color)
{
    this->position = position;
    this->color = color;
    this->size = size;

    mpaddle.setFillColor(this->color);
    mpaddle.setPosition(this->position);
    mpaddle.setSize(this->size);
}

/*Implement a drawPaddle method for draw on screen*/
void Paddle::drawPaddle(sf::RenderWindow &window)
{
    window.draw(this->mpaddle);
}

/* Get a paddle positios */

sf::Vector2f Paddle::getPaddlePosition()
{
    return this->position;
}
/*Implement  a setter for mpaddle private membet of paddle*/
void Paddle::setPaddlePosition(sf::Vector2f position)
{
    this->position = position;
    mpaddle.setPosition(this->position);
}

// Paddle::getPaddle()
// {
//     return this->mpaddle;
// }
