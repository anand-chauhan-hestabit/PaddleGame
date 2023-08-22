#include "/home/hestabit/Desktop/PaddleGame/headerFiles/rpc.hpp"

inline sf::Packet &operator>>(sf::Packet &packet, PaddlePosition &paddlePosition)
{
    packet >> paddlePosition.x;
    packet >> paddlePosition.y;
    return packet;
}

void RPC::sendPaddlePosition(float x, float y)
{
    // Create a packet to store the paddle position.
    sf::Packet packet;

    // Pack the paddle position into the packet.
    packet << x;
    packet << y;

    // Send the paddle position to the server.
    if (isServer)
    {
        serverSocket.sendGameData(packet);
    }
    else
    {
        clientSocket.sendGameData(packet);
    }
}

PaddlePosition RPC::receivePaddlePosition()
{
    // Create a packet to store the paddle position.
    sf::Packet packet;

    // Receive the paddle position from the server.
    if (isServer)
    {
        serverSocket.receiveGameData(packet);
    }
    else
    {
        clientSocket.receiveGameData(packet);
    }

    // Extract the paddle position from the packet.
    PaddlePosition paddlePosition;
    packet >> paddlePosition;

    return paddlePosition;
}
