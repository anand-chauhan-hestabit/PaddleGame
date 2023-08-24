#ifndef RPC_HPP
#define RPC_HPP
#include <iostream>
#include <string>
#include "/home/hestabit/Desktop/PaddleGame/headerFiles/client.hpp"
#include "/home/hestabit/Desktop/PaddleGame/headerFiles/server.hpp"

struct GameState
{
    sf::Vector2f paddlePosition;
    sf::Vector2f ballPosition;
    int score[2];
};

inline sf::Packet &operator>>(sf::Packet &packet, GameState &gameState);

inline sf::Packet &operator<<(sf::Packet &packet, const GameState &gameState);

class RPC
{
public:
    RPC() {} // RPC constructor

    void sendGameState(const GameState &gameState);

    GameState receiveGameState();

public:
    bool isServer;
    Server serverSocket;
    Client clientSocket;
};

#endif // RPC_HPP
