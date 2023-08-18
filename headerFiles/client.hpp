#ifndef CLIENT_HPP
#define CLIENT_HPP

#include"/home/hestabit/Desktop/PaddleGame/Library/SFML/include/SFML/Network.hpp"
class Client
{
public:
    Client();

    void connectToServer(const std::string& serverIP, unsigned short serverPort);
    void sendGameData(sf::Packet& packet);
    void receiveGameData(sf::Packet& packet);
    void disconnect();

private:
    sf::TcpSocket socket;
};

#endif // CLIENT_HPP