#ifndef RPC_HPP
#define RPC_HPP
#include <iostream>
#include <string>
#include "client.hpp"
#include "server.hpp"

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

    bool isConnected();

public:
    bool isServer;
    Server serverSocket;
    Client clientSocket;
};

#endif // RPC_HPP
