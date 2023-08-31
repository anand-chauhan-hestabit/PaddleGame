#ifndef ONLINE_HPP
#define ONLINE_HPP
// #include "assets/color/color.hpp"
#include "../Library/SFML/include/SFML/Graphics.hpp"
#include "UserInterface/UserInterFace.hpp"
#include "Ball/ball.hpp"
#include "Player/player.hpp"
#include "NetworkManager/rpc.hpp"
#include <string>
#include"../MainMenu.hpp"


#include <iostream>
using namespace std;
class OnlineMode
{
private:
sf::RenderWindow &window;

public:
  OnlineMode(sf::RenderWindow &newWindow);

  ~OnlineMode();
};


#endif // ONLINE_HPP