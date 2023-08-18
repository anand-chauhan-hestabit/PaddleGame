#include <iostream>
#include <string>
#include "/home/hestabit/Desktop/PaddleGame/headerFiles/client.hpp"
#include "/home/hestabit/Desktop/PaddleGame/headerFiles/server.hpp"

int main()
{
    int choice;
    std::cout << "Choose an option:\n";
    std::cout << "1. Run as server\n";
    std::cout << "2. Run as client\n";
    std::cout << "Your choice: ";
    std::cin >> choice;

    if (choice == 1)
    {
        // Run as server
        Server server;
        server.startListening(5500);
        server.acceptClient();
        while (true)
        {

            sf::Packet receivedPacket;
            server.receiveGameData(receivedPacket);

            int clientValue;
            receivedPacket >> clientValue;
            std::cout << "Received value from client: " << clientValue << std::endl;

            int newValue = clientValue + 5;

            sf::Packet packetToSend;
            packetToSend << newValue;
            server.sendGameData(packetToSend);
        }
    }
    else if (choice == 2)
    {
        // Run as client
        Client client;
        std::string serverIP;
        unsigned short serverPort;

        std::cout << "Enter server IP: ";
        std::cin >> serverIP;
        std::cout << "Enter server port: ";
        std::cin >> serverPort;
        
        client.connectToServer(serverIP, serverPort);

        if (!client.getSocket().isValid())
        {
            std::cerr << "Failed to connect to the server.\n";
            return 1;
        }

        while (true)
        {
            int clientValue;
            std::cout << "Enter an integer value to send to server: ";
            std::cin >> clientValue;

            sf::Packet packetToSend;
            packetToSend << clientValue;
            client.sendGameData(packetToSend);

            sf::Packet receivedPacket;
            client.receiveGameData(receivedPacket);

            int serverValue;
            receivedPacket >> serverValue;
            std::cout << "Received value from server: " << serverValue << std::endl;
        }
    }
    else
    {
        std::cout << "Invalid choice.\n";
        return -1;
    }

    return 0;
}