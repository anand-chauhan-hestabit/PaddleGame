#include "../../headerFiles/SoundManager/soundManager.hpp"

SoundManager::SoundManager()
{

    // Load a music to play
    if (!setSoundBuffer[0].loadFromFile("assets/audio/ball.wav"))
        std::cerr << "Failed to load paddleHit.wav" << std::endl;
    else
        setSound[0].setBuffer(setSoundBuffer[0]);

    if (!setSoundBuffer[1].loadFromFile("assets/audio/winner.wav"))
        std::cerr << "Failed to load winner.wav" << std::endl;
    else
        setSound[1].setBuffer(setSoundBuffer[1]);

    if (!setSoundBuffer[2].loadFromFile("assets/audio/gameOver.wav"))
        std::cerr << "Failed to load loser.wav" << std::endl;
    else
        setSound[2].setBuffer(setSoundBuffer[2]);
}

void SoundManager::playSound(const std::string &sound)
{

    std::vector<std::string> sounds{"ball_Paddle_Collide", "gameStart", "gameOver"};

    // Loop through the string array using a traditional for loop
    for (int i = 0; i < sounds.size(); ++i)
    {
        if (sounds[i] == sound)
            setSound[i].play();
    }
}


void SoundManager::pauseSound(const std::string &sound)
{

    std::vector<std::string> sounds{"ball_Paddle_Collide", "gameStart", "gameOver"};

    // Loop through the string array using a traditional for loop
    for (int i = 0; i < sounds.size(); ++i)
    {
        if (sounds[i] == sound)
            setSound[i].pause();
    }
}