#ifndef SoundManager_HPP
#define SoundManager_HPP
#include <iostream>
#include <string.h>
#include <vector>
#include "../../Library/SFML/include/SFML/Audio.hpp"
#include "../../Library/SFML/include/SFML/Graphics.hpp"

using namespace std;

class SoundManager
{
private:
    // Load a music to play
    // sf::Music paddle_Hit;
    // sf::Music winner_Sound;
    // // sf::Music music;
    sf::SoundBuffer setSoundBuffer[3];

    sf::Sound setSound[3];

public:
    SoundManager();
    void playSound(const std::string& sound);
    void pauseSound(const std::string& sound);
};

#endif // SoundManager_HPP