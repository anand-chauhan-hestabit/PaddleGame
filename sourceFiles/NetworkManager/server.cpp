#include "../../headerFiles/NetworkManager/server.hpp"

Server::Server()
{
}

void Server::startListening(unsigned short port)
{
    listener.listen(port);
}

void Server::acceptClient()
{
    if (listener.accept(clientSocket) != sf::Socket::Done)
    {
        // std::cout << "Not connected server with client " << std::endl;
        return;
    }
    // std::cout << "Server is connected with client ipAdress :   " <<clientSocket.getRemoteAddress() << ":" << clientSocket.getRemotePort() << std::endl;
}

void Server::sendGameData(sf::Packet &packet)
{
    clientSocket.send(packet);
}

void Server::receiveGameData(sf::Packet &packet)
{
    clientSocket.receive(packet);
}

bool Server ::isClietConnected()
{
    return clientSocket.getRemoteAddress() != sf::IpAddress::None;
    
}

void Server::disconnect()
{
    clientSocket.disconnect();
}
