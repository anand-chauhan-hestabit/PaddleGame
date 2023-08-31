#ifndef SERVER_HPP
#define SERVER_HPP
#include<iostream>

#include"../../Library/SFML/include/SFML/Network.hpp"

class Server
{
public:
    Server();

    void startListening(unsigned short port);
    void acceptClient();
    void sendGameData(sf::Packet& packet);
    void receiveGameData(sf::Packet& packet);
    void disconnect();
    bool isClietConnected();

private:
    sf::TcpListener listener;
    sf::TcpSocket clientSocket;
};

#endif // SERVER_HPP