#ifndef BALL_HPP
#define BALL_HPP
#include "../../Library/SFML/include/SFML/Graphics.hpp"
#include "../Player/paddle.hpp"
#include "../Player/player.hpp"
#include "../SoundManager/soundManager.hpp"

using namespace sf;

class Ball
{
public: /*Public Properties of Ball class*/
  float radius;
  Vector2f position;
  Vector2f velocity;
  Color color;
  SoundManager sound;

private:
  sf::CircleShape msfml_ball; /*Private Properties of Ball class*/

public:
  Ball(); /*Default constructor */
  Ball(float radius, Vector2f position, Color color); /*Public methods of Ball class*/
                                                      /*
                                                    Set the properties for moveBall
                                                    @param first-Arg for set the screen
                                                    @param second-vector for set the size
                                                    @param third parameter set the coloru
                                                    */
  sf::Vector2f getBallPosition();

  void setBallPosition(sf::Vector2f newBallPosition);

  void moveBall(Player &first_player, Player &second_player);

  void resetBallAfterInning();

  void check_ball_paddle_collision(Ball &ball, Player &first_player, Player &second_player);

  void drawball(sf::RenderWindow &window);
  // void update(float ball_position_x, float ball_position_y, float speed_, float speed_y);
};

#endif // BALL_HPP
