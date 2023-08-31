#ifndef OFFLINE_HPP
#define OFFLINE_HPP
// #include "../assets/color/color.hpp"
#include "../Library/SFML/include/SFML/Graphics.hpp"
#include "../headerFiles/UserInterface/UserInterFace.hpp"
#include "Ball/ball.hpp"
#include "Player/player.hpp"
#include "NetworkManager/rpc.hpp"
#include"../MainMenu.hpp"

#include <iostream>

using namespace std;

class OfflineMode
{
private:
    sf::RenderWindow &window;

public:
  OfflineMode(sf::RenderWindow &window);
  ~OfflineMode();
};

#endif // OFFLINE_HPP