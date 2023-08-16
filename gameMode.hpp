#ifndef GAMEMODE_HPP
#define GAMEMODE_HPP
#include "assets/color/color.hpp"
#include "Library/SFML/include/SFML/Graphics.hpp"
#include "headerFiles/UserInterFace.hpp"
#include "headerFiles/ball.hpp"
#include "headerFiles/player.hpp"

#include <iostream>
using namespace std;
class gameMode
{
private:
public:
  gameMode();
  ~gameMode();
};

gameMode::gameMode()
{
  unsigned short framerate = 60.0f;

  unsigned short screen_width = sf::VideoMode::getDesktopMode().width;   // Get Desktop width
  unsigned short screen_height = sf::VideoMode::getDesktopMode().height; // Get Desktop height
  // cout << screen_width << screen_height << endl;

  // screen_width = screen_width - 140;
  // screen_height = screen_height - 115;

  sf::RenderWindow window;

  /*  Arg->Argument
  Set the properties for Ball
  @param first-Arg set ball radius
  @param second-Arg set the ball position
  @param third-Arg set ball color
  */
  Ball ball(25.0f, Vector2f(screen_width/2, screen_height/2), sf::Color::Red);

  /*
    Set the properties for UserInterFace
    @param first-Arg argument set the char size
    @param second-Arg for set the color
    @param third parameter set the position
    */
  UserInterFace *ui = new UserInterFace(50, sf::Color::White, Vector2f(screen_width, screen_height));

  /*
  Set the properties for firstPlayer
  @param first-vector for set the postions
  @param second-vector for set the size
  @param third parameter set the color
  */
  Player firstPlayer(Vector2f(screen_width * 0, (screen_height / 2) - 125), Vector2f(25, 120), sf::Color::Green);
  firstPlayer.setInputKey(sf::Keyboard::W, sf::Keyboard::S);

  /*
    Set the properties for secondPlayer
    @param first-vector for set the postions
    @param second-vector for set the size
    @param third parameter set the color
    */
  Player secondPlayer(Vector2f(screen_width - 25, (screen_height / 2) - 125), Vector2f(25, 120), sf::Color::Green);
  secondPlayer.setInputKey(sf::Keyboard::Up, sf::Keyboard::Down);

  /*Windows creted with screen_width and screen_height and in FullScreen mode*/
  window.create(sf::VideoMode(screen_width, screen_height), "Paddle Game", sf::Style::Fullscreen);
  window.setFramerateLimit(framerate);
  while (window.isOpen())
  {

    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
      // Press escape for exit
      else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
      {
        window.close();
      }
    }
    /*
    Updating a object with methods 

    scree_width and screen_height for moving a ball across the window
    @param firstPlyer for the update the score
    @param secondPlayer for the update the score
    */
    ball.moveBall(screen_width, screen_height, firstPlayer, secondPlayer);
    firstPlayer.updatePostion();
    secondPlayer.updatePostion();
    ui->updateScore(firstPlayer.score, secondPlayer.score); //Update the score ui
    ball.check_ball_paddle_collision(ball, firstPlayer, secondPlayer); // check collisions

    /*clear the screen */
    window.clear();

    /*drawing a object on screens*/
    ui->drawFirstScore(window);
    ui->drawSecondScore(window);
    ui->drawGameStatus(window);
    firstPlayer.draw(window);  // Draw a firstPlayer on game screen
    secondPlayer.draw(window); // Draw a secondPlayer on game screen
    ball.drawball(window);     // Draw a ball on screen
    window.display();
    
  }
}

gameMode::~gameMode()
{
}

#endif // GAMEMODE_HPP