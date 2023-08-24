
#include "../headerFiles/ball.hpp"
#include <unistd.h>
#include <ctime>

#include <iostream>
using namespace std;
// ball constructor
Ball::Ball(float radius, Vector2f position, Color color)
{
    this->radius = radius;
    this->position = position;
    this->color = color;
    this->velocity = Vector2f(12, 12);
    msfml_ball.setRadius(this->radius);
    msfml_ball.setPosition(this->position.x / 2, this->position.y / 2);
    msfml_ball.setFillColor(this->color);
}
// draw a ball
void Ball::drawball(sf::RenderWindow &window)
{
    window.draw(this->msfml_ball);
}

// moving a ball
void Ball::moveBall(float screenWidth, float screenHeight, Player &first_player, Player &second_player)
{
    // Update the ball's position based on its velocity
    this->position.x += this->velocity.x;
    this->position.y += this->velocity.y;

    // Check if the ball hits the left or right boundary
    if (this->position.x < 0)
    {

        // second_player.score++; /*Increment a score*/

        resetBallAfterInning(); /*Ball Reset After win or loss condition*/
    }
    else if (this->position.x >= sf::VideoMode::getDesktopMode().width)
    {

        // first_player.score++; /*Increament a score*/

        resetBallAfterInning(); /*Ball Reset After win or loss condition*/
    }

    // Check if the ball hits the top or bottom boundary
    if (this->position.y <= 0)
    {
        // this->position.y = this->radius;
        this->velocity.y = -this->velocity.y;
    }
    else if (this->position.y >= sf::VideoMode::getDesktopMode().height - 2 * this->radius)
    {
        this->velocity.y = -this->velocity.y;
    }

    // msfml_ball.setPosition(this->position);
}

/*ball paddle collision detection*/
void Ball::check_ball_paddle_collision(Ball &ball, Player &first_player, Player &second_player)
{
    if (ball.msfml_ball.getGlobalBounds().intersects(first_player.getPaddle()->mpaddle.getGlobalBounds()))
    {
        // Collision detected!
        ball.msfml_ball.setFillColor(sf::Color::Yellow);
        ball.velocity.x *= -1;
        ball.msfml_ball.setPosition(ball.msfml_ball.getPosition() + ball.velocity);
    }
    if (ball.msfml_ball.getGlobalBounds().intersects(second_player.getPaddle()->mpaddle.getGlobalBounds()))
    {
        // Collision detected!
        ball.msfml_ball.setFillColor(sf::Color::Red);
        ball.velocity.x *= -1;
        ball.msfml_ball.setPosition(ball.msfml_ball.getPosition() + ball.velocity);
    }
}

/*Reset the ball after inning*/
void Ball::resetBallAfterInning()
{
    position.x = sf::VideoMode::getDesktopMode().width / 2;
    position.y = sf::VideoMode::getDesktopMode().height / 2;
}