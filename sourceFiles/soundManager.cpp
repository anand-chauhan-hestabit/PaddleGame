#include "../headerFiles/soundManager.hpp"

soundManager::soundManager()
{

    // Load a music to play
    if (!paddle_Hit.openFromFile("/home/hestabit/Desktop/Programming/GameCode/PaddleGame/assets/audio/paddleHit.wav"))
        return EXIT_FAILURE;
}

soundManager::playsound(string sound)
{

    if (sound == "paddle_Hit")
    {
        paddle_Hit.play();
    }
}