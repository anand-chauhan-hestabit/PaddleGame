
#include "../../headerFiles/Ball/ball.hpp"
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
    this->velocity = Vector2f(10, 10);
    msfml_ball.setRadius(this->radius);
    msfml_ball.setPosition(this->position.x / 2, this->position.y / 2);
    msfml_ball.setFillColor(this->color);
}
// draw a ball
void Ball::drawball(sf::RenderWindow &window)
{
    window.draw(this->msfml_ball);
}

/*Getter-> Get a ball */
sf::Vector2f Ball::getBallPosition()
{
    return this->position;
}

/*Setter-> Set Ball New Positons */
void Ball::setBallPosition(sf::Vector2f NewBallpostions)
{

    msfml_ball.setPosition(NewBallpostions);
}

// moving a ball
void Ball::moveBall(Player &first_player, Player &second_player)
{
    // Update the ball's position based on its velocity
    this->position.x += this->velocity.x;
    this->position.y += this->velocity.y;


    // Check if the ball hits the left or right boundary
    if (this->position.x < 0)
    {

        second_player.score++; /*Increment a score*/

        resetBallAfterInning(); /*Ball Reset After win or loss condition*/
    }
    else if (this->position.x >= sf::VideoMode::getDesktopMode().width)
    {

        first_player.score++; /*Increament a score*/

        resetBallAfterInning(); /*Ball Reset After win or loss condition*/
    }

    // Check if the ball hits the top or bottom boundary
    if (this->position.y <= 0)
    {
        this->velocity.y *= -1;

    }
    else if (this->position.y >= sf::VideoMode::getDesktopMode().height - 2 * this->radius)
    {
        this->velocity.y *= -1;
    }
}

/*ball paddle collision detection*/
void Ball::check_ball_paddle_collision(Ball &ball, Player &first_player, Player &second_player)
{
    
    if (ball.msfml_ball.getGlobalBounds().intersects(first_player.getPaddle()->mpaddle.getGlobalBounds()))
    {   
        sound.playSound("ball_Paddle_Collide");
        // Collision detected!
        // ball.msfml_ball.setFillColor(sf::Color::Yellow);
        
        velocity.x *= -1;

        // ball.msfml_ball.setPosition(ball.msfml_ball.getPosition() + ball.velocity);
    }
    if (ball.msfml_ball.getGlobalBounds().intersects(second_player.getPaddle()->mpaddle.getGlobalBounds()))
    {
        // Collision detected!
        sound.playSound("ball_Paddle_Collide");
        // ball.msfml_ball.setFillColor(sf::Color::Red);
        velocity.x *= -1;

        // ball.msfml_ball.setPosition(ball.msfml_ball.getPosition() + ball.velocity);
    }
}

/*Reset the ball after inning*/
void Ball::resetBallAfterInning()
{   
    sound.playSound("gameOver");
    position.x = sf::VideoMode::getDesktopMode().width / 2;
    position.y = sf::VideoMode::getDesktopMode().height / 2;
}