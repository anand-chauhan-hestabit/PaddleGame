#include "../../headerFiles/NetworkManager/client.hpp"

Client::Client()
{
}

void Client::connectToServer(const std::string &serverIP, unsigned short serverPort)
{
    sf::Socket::Status status = socket.connect(serverIP, serverPort);
    if (status != sf::Socket::Done)
    {
        // error...
        // std::cout << "Client not connected with server " << std::endl;
        isServerConnected = false;
        return;
    }
    isServerConnected = true;
    // std::cout << "Client is connected with server with Adress : " << socket.getRemoteAddress() << ":" << socket.getRemotePort() << std::endl;
}

void Client::sendGameData(sf::Packet &packet)
{
    socket.send(packet);
}

void Client::receiveGameData(sf::Packet &packet)
{
    socket.receive(packet);
}

void Client::disconnect()
{
    socket.disconnect();
}