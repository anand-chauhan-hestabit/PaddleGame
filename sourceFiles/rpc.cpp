#include "/home/hestabit/Desktop/PaddleGame/headerFiles/rpc.hpp"

/*Serialize a gamestateData*/

inline sf::Packet &operator>>(sf::Packet &packet, GameState &gameState)
{
    return packet >> gameState.paddlePosition.x >> gameState.paddlePosition.y >> gameState.ballPosition.x >> gameState.ballPosition.y;
}
/*Deserialize a gamestateData*/

inline sf::Packet &operator<<(sf::Packet &packet, const GameState &gameState)
{
    return packet << gameState.paddlePosition.x << gameState.paddlePosition.y
                  << gameState.ballPosition.x << gameState.ballPosition.y;
}

/*Send a gameState*/
void RPC::sendGameState(const GameState &gameState)
{
    sf::Packet packet;
    packet << gameState;

    if (isServer)
    {
        serverSocket.sendGameData(packet);
    }
    else
    {
        clientSocket.sendGameData(packet);
    }
}

/*Receive a gameState*/
GameState RPC::receiveGameState()
{
    sf::Packet packet;
    if (isServer)
    {
        serverSocket.receiveGameData(packet);
    }
    else
    {
        clientSocket.receiveGameData(packet);
    }

    GameState gameState;
    packet >> gameState;
    return gameState;
}