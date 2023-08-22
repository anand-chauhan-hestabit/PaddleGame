#ifndef SoundManager_HPP
#define SoundManager_HPP
#include<string>
#include "../Library/SFML/Graphics.hpp"
#include "../Library/SFML/Audio.hpp"

class SoundManager
{
private:
      // Load a music to play
    sf::Music paddle_Hit;
    sf::Music winner_Sound;
public:
    SoundManager(/* args */);
    void playsound(string sound);
    ~SoundManager();
};

SoundManager::SoundManager(/* args */)
{
}

SoundManager::~SoundManager()
{
}



#endif // SoundManager_HPP