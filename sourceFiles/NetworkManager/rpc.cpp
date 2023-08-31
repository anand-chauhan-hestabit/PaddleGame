#include "../../headerFiles/NetworkManager/rpc.hpp"

/*Serialize a gamestateData*/

inline sf::Packet &operator>>(sf::Packet &packet, GameState &gameState)
{
    return packet >> gameState.paddlePosition.x >> gameState.paddlePosition.y 
    >> gameState.ballPosition.x >> gameState.ballPosition.y 
    >> gameState.score[0] >> gameState.score[1];
}
/*Deserialize a gamestateData*/

inline sf::Packet &operator<<(sf::Packet &packet, const GameState &gameState)
{
    return packet << gameState.paddlePosition.x << gameState.paddlePosition.y
                  << gameState.ballPosition.x << gameState.ballPosition.y
                  << gameState.score[0] << gameState.score[1];
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

bool RPC::isConnected()
{
    if(isServer)
    {
       return serverSocket.isClietConnected();
    }
}