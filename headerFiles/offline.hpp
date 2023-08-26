#ifndef OFFLINE_HPP
#define OFFLINE_HPP
#include "../assets/color/color.hpp"
#include "../Library/SFML/include/SFML/Graphics.hpp"
#include "../headerFiles/UserInterFace.hpp"
#include "ball.hpp"
#include "player.hpp"
#include "rpc.hpp"

#include <iostream>

using namespace std;

class OfflineMode
{
private:
public:
  OfflineMode();
  ~OfflineMode();
};

#endif // OFFLINE_HPP