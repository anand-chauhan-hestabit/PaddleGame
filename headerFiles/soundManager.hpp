#ifndef SOUNDMANAGER_HPP
#define SOUNDMANAGER_HPP
#include<string>
#include "../Library/SFML/Graphics.hpp"
#include "../Library/SFML/Audio.hpp"

class soundManager
{
private:
      // Load a music to play
    sf::Music paddle_Hit;
    sf::Music winner_Sound;
public:
    soundManager(/* args */);
    void playsound(string sound);
    ~soundManager();
};

soundManager::soundManager(/* args */)
{
}

soundManager::~soundManager()
{
}



#endif // SOUNDMANAGER_HPP