#include <iostream>
#include <string>
#include "/home/hestabit/Desktop/PaddleGame/headerFiles/client.hpp"
#include "/home/hestabit/Desktop/PaddleGame/headerFiles/server.hpp"
// // #include "ram.hpp"
// #

// int main()
// {
//     int choice;
//     std::cout << "Choose an option:\n";
//     std::cout << "1. Run as server\n";
//     std::cout << "2. Run as client\n";
//     std::cout << "Your choice: ";
//     std::cin >> choice;

//     if (choice == 1)
//     {
//         // Run as server
//         Server server;
//         server.startListening(5500);
//         server.acceptClient();
//         while (true)
//         {

//             sf::Packet receivedPacket;
//             server.receiveGameData(receivedPacket);

//             Ram *ram = new Ram;
//             receivedPacket >> ram->floatvalue >> ram->number;
//             std::cout << "Received value from client beore update : " << ram->floatvalue << "  " << ram->number << std::endl;

//             ram->floatvalue += 100;
//             ram->number += 100;

//             std::cout << "Received value from client after update : " << ram->floatvalue << "  " << ram->number << std::endl;

//             // int newValue = clientValue + 5;

//             // sf::Packet packetToSend;
//             // packetToSend << newValue;
//             // server.sendGameData(packetToSend);
//         }
//     }
//     else if (choice == 2)
//     {
//         // Run as client
//         Client client;
//         // std::string serverIP;
//         // unsigned short serverPort;

//         // std::cout << "Enter server IP: ";
//         // std::cin >> serverIP;
//         // std::cout << "Enter server port: ";
//         // std::cin >> serverPort;

//         client.connectToServer("localhost", 5500);

//         while (true)
//         {
//             // int clientValue;
//             // std::cout << "Enter an integer value to send to server: ";
//             // std::cin >> clientValue;

//             Ram *ram = new Ram;
//             ram->number = 10;
//             ram->floatvalue = 14.33;

//             sf::Packet packetToSend;
//             packetToSend << ram->floatvalue << ram->number;
//             client.sendGameData(packetToSend);

//             std::cout << "  client code .... Received value from client: after update" << ram->floatvalue << "  " << ram->number << std::endl;

//             // sf::Packet receivedPacket;
//             // client.receiveGameData(receivedPacket);

//             // int serverValue;
//             // receivedPacket >> serverValue;
//             // std::cout << "Received value from server: " << serverValue << std::endl;
//         }
//     }
//     else
//     {
//         std::cout << "Invalid choice.\n";
//         return -1;
//     }

//     return 0;
// }

#include </home/hestabit/Desktop/PaddleGame/Library/SFML/include/SFML/Network.hpp>

struct PaddlePosition {
  float x;
  float y;
};

inline sf::Packet& operator>>(sf::Packet& packet, PaddlePosition& paddlePosition) {
  packet >> paddlePosition.x;
  packet >> paddlePosition.y;
  return packet;
}

class RPC {
public:
  RPC() {}

  void sendPaddlePosition(float x, float y) {
    // Create a packet to store the paddle position.
    sf::Packet packet;

    // Pack the paddle position into the packet.
    packet << x;
    packet << y;

    // Send the paddle position to the server.
    if (isServer) {
      serverSocket.sendGameData(packet);
    } else {
      clientSocket.sendGameData(packet);
    }
  }

  PaddlePosition receivePaddlePosition() {
    // Create a packet to store the paddle position.
    sf::Packet packet;

    // Receive the paddle position from the server.
    if (isServer) {
      serverSocket.receiveGameData(packet);
    } else {
      clientSocket.receiveGameData(packet);
    }

    // Extract the paddle position from the packet.
    PaddlePosition paddlePosition;
    packet >> paddlePosition;

    return paddlePosition;
  }

  bool isServer;

public:
  Server serverSocket;
  Client clientSocket;
};

int main() {
  // Create an RPC object.
  RPC rpc;

  // Get the user's choice.
  std::string choice;
  std::cout << "Do you want to be the server (s) or the client (c)?" << std::endl;
  std::cin >> choice;

  // Set the RPC object's isServer flag.
  if (choice == "s") {
    rpc.isServer = true;
  } else {
    rpc.isServer = false;
  }

  // Start the server or client.
  if (rpc.isServer) {
    // Start the server socket.
    rpc.serverSocket.startListening(5500);
    rpc.serverSocket.acceptClient();

    // Accept a connection from the client.
  } else {
    // Connect to the server.
    rpc.clientSocket.connectToServer("localhost", 5500);
  }

  // Send the paddle position to the server or client.
  rpc.sendPaddlePosition(4564, 100);

  // Receive the paddle position from the server or client.
  PaddlePosition paddlePosition = rpc.receivePaddlePosition();

  // Print the received paddle position.
  std::cout << "Received paddle position: " << paddlePosition.x << ", " << paddlePosition.y << std::endl;

  
  return 0;
}
