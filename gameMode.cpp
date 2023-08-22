// /*gameMode.cpp file and main method*/
// #include "gameMode.hpp"

// GameMode::GameMode()
// {
//     int choice;
//     std::cout << "Choose an option:\n";
//     std::cout << "1. Run as server\n";
//     std::cout << "2. Run as client\n";
//     std::cout << "Your choice: ";
//     std::cin >> choice;

//     if (choice == 1)
//     {

//         Server server;
//         server.startListening(5500);
//         server.acceptClient();

//         unsigned short framerate = 60.0f;

//         unsigned short screen_width = sf::VideoMode::getDesktopMode().width;   // Get Desktop width
//         unsigned short screen_height = sf::VideoMode::getDesktopMode().height; // Get Desktop height

//         // screen_width = screen_width - 140;
//         // screen_height = screen_height - 115;
//         sf::RenderWindow window;

//         /*  Arg->Argument
//         Set the properties for Ball
//         @param first-Arg set ball radius
//         @param second-Arg set the ball position
//         @param third-Arg set ball color
//         */
//         Ball ball(25.0f, Vector2f(screen_width / 2, screen_height / 2), sf::Color::Red);

//         /*
//           Set the properties for UserInterFace
//           @param first-Arg argument set the char size
//           @param second-Arg for set the color
//           @param third parameter set the position
//           */
//         UserInterFace *ui = new UserInterFace(50, sf::Color::White, Vector2f(screen_width, screen_height));

//         /*
//         Set the properties for firstPlayer
//         @param first-vector for set the postions
//         @param second-vector for set the size
//         @param third parameter set the color
//         */
//         Player firstPlayer(Vector2f(screen_width * 0, (screen_height / 2) - 125), Vector2f(25, 120), sf::Color::Green);
//         firstPlayer.setInputKey(sf::Keyboard::W, sf::Keyboard::S);

//         /*
//           Set the properties for secondPlayer
//           @param first-vector for set the postions
//           @param second-vector for set the size
//           @param third parameter set the color
//           */
//         Player secondPlayer(Vector2f(screen_width - 25, (screen_height / 2) - 125), Vector2f(25, 120), sf::Color::Green);
//         // secondPlayer.setInputKey(sf::Keyboard::Up, sf::Keyboard::Down);

//         // secondPlayer.getPaddle()->setUpdatePosition()

//         /*Windows creted with screen_width and screen_height and in FullScreen mode*/ // sf::Style::Fullscreen
//         window.create(sf::VideoMode(screen_width, screen_height), "Server - Paddle Game");
//         window.setFramerateLimit(framerate);

//         struct gameData
//         {
//             sf::Vector2f PlayerPaddlePositions[2];
//             int PlayerScore[2];
//         };

//         while (window.isOpen())
//         {

//             sf::Event event;
//             while (window.pollEvent(event))
//             {
//                 if (event.type == sf::Event::Closed)
//                     window.close();
//                 // Press escape for exit
//                 else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
//                 {
//                     window.close();
//                 }
//             }

//             /*
//             Update a object with methods

//             scree_width and screen_height for moving a ball across the window
//             @param firstPlyer for the update the score
//             @param secondPlayer for the update the score
//             */
//             sf::Packet receivedPacket; // Recieve packet
//             gameData gameDataToReceive;
//             server.receiveGameData(receivedPacket);
//             // receivedPacket >> clientPaddlePosition.x >> clientPaddlePosition.y;
//             receivedPacket >> gameDataToReceive.PlayerPaddlePositions[0].x >> gameDataToReceive.PlayerPaddlePositions[0].y;
//             // std::cout << "Received paddle position from client: (" << clientPaddlePosition.x << ", " << clientPaddlePosition.y << ")\n";
//             std::cout << "Received paddle position from client:" << gameDataToReceive.PlayerPaddlePositions[0].x << "   " << gameDataToReceive.PlayerPaddlePositions[0].y << " " << gameDataToReceive.PlayerScore[0] << endl;

//             ball.moveBall(screen_width, screen_height, firstPlayer, secondPlayer);

//             sf::Packet packetToSend; // send packet
//             gameData gameDataToSend;

//             // firstPlayer.updatePostion();
//             firstPlayer.getInput()->update_paddle_position();
//             gameDataToSend.PlayerPaddlePositions[1].x = firstPlayer.getInput()->newPaddlePositions.x;
//             gameDataToSend.PlayerPaddlePositions[1].y = firstPlayer.getInput()->newPaddlePositions.y;

//             // now send the packet to update
//             packetToSend << gameDataToReceive.PlayerPaddlePositions[0].x << gameDataToReceive.PlayerPaddlePositions[0].y << gameDataToSend.PlayerPaddlePositions[1].x << gameDataToSend.PlayerPaddlePositions[1].y;
//             server.sendGameData(packetToSend);

//             // secondPlayer.updatePostion();
//             // secondPlayer.getPaddle()->setUpdatePosition(clientPaddlePosition);

//             firstPlayer.getPaddle()->setUpdatePosition(gameDataToSend.PlayerPaddlePositions[1]);

//             secondPlayer.getPaddle()->setUpdatePosition(gameDataToReceive.PlayerPaddlePositions[0]);

//             ui->updateScore(firstPlayer.score, secondPlayer.score);            // Update the score ui
//             ball.check_ball_paddle_collision(ball, firstPlayer, secondPlayer); // check collisions

//             /*clear the screen */
//             window.clear();

//             /*drawing a object on screens*/
//             ui->drawFirstScore(window);
//             ui->drawSecondScore(window);
//             ui->drawGameStatus(window);
//             firstPlayer.draw(window);  // Draw a firstPlayer on game screen
//             secondPlayer.draw(window); // Draw a secondPlayer on game screen
//             ball.drawball(window);     // Draw a ball on screen
//             window.display();
//         }
//         // server.disconnect();
//     }

//     else if (choice == 2)
//     {
//         Client client;

//         std::string serverIP;
//         unsigned short serverPort;

//         std::cout << "Enter server IP: ";
//         std::cin >> serverIP;
//         std::cout << "Enter server port: ";
//         std::cin >> serverPort;

//         client.connectToServer(serverIP, serverPort);

//         unsigned short framerate = 60.0f;

//         unsigned short screen_width = sf::VideoMode::getDesktopMode().width;   // Get Desktop width
//         unsigned short screen_height = sf::VideoMode::getDesktopMode().height; // Get Desktop height

//         // screen_width = screen_width - 140;
//         // screen_height = screen_height - 115;

//         sf::RenderWindow window;

//         /*  Arg->Argument
//         Set the properties for Ball
//         @param first-Arg set ball radius
//         @param second-Arg set the ball position
//         @param third-Arg set ball color
//         */
//         Ball ball(25.0f, Vector2f(screen_width / 2, screen_height / 2), sf::Color::Red);

//         /*
//           Set the properties for UserInterFace
//           @param first-Arg argument set the char size
//           @param second-Arg for set the color
//           @param third parameter set the position
//           */
//         UserInterFace *ui = new UserInterFace(50, sf::Color::White, Vector2f(screen_width, screen_height));

//         /*
//         Set the properties for firstPlayer
//         @param first-vector for set the postions
//         @param second-vector for set the size
//         @param third parameter set the color
//         */
//         Player firstPlayer(Vector2f(screen_width * 0, (screen_height / 2) - 125), Vector2f(25, 120), sf::Color::Green);
//         // firstPlayer.setInputKey(sf::Keyboard::W, sf::Keyboard::S);

//         /*
//           Set the properties for secondPlayer
//           @param first-vector for set the postions
//           @param second-vector for set the size
//           @param third parameter set the color
//           */
//         Player secondPlayer(Vector2f(screen_width - 25, (screen_height / 2) - 125), Vector2f(25, 120), sf::Color::Green);
//         secondPlayer.setInputKey(sf::Keyboard::Up, sf::Keyboard::Down);

//         /*Windows creted with screen_width and screen_height and in FullScreen mode*/ //, sf::Style::Fullscreen
//         window.create(sf::VideoMode(screen_width, screen_height), "Client - Paddle Game");

//         window.setFramerateLimit(framerate);

//         /* Define a structure to hold the data*/
//         struct gameData
//         {
//             sf::Vector2f clientPaddlePositions[2];
//             int playerScore[2];
//         };

//         // gameData gameDataTosend;

//         while (window.isOpen())
//         {

//             sf::Event event;
//             while (window.pollEvent(event))
//             {
//                 if (event.type == sf::Event::Closed)
//                     window.close();
//                 // Press escape for exit
//                 else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
//                 {
//                     window.close();
//                 }
//             }
//             /*
//             Update a object with methods

//             scree_width and screen_height for moving a ball across the window
//             @param firstPlyer for the update the score
//             @param secondPlayer for the update the score
//             */

//             ball.moveBall(screen_width, screen_height, firstPlayer, secondPlayer); // update ball positions and detecting  collision and track a score

//             secondPlayer.getInput()->update_paddle_position();

//             sf::Packet packetToSend; // paccket types data declare
//             gameData gameDataTosend;

//             gameDataTosend.clientPaddlePositions[0].x = secondPlayer.getInput()->newPaddlePositions.x;
//             gameDataTosend.clientPaddlePositions[0].y = secondPlayer.getInput()->newPaddlePositions.y;
//             gameDataTosend.playerScore[0] = secondPlayer.score;
//             cout << "gamedata updated " << gameDataTosend.clientPaddlePositions[0].y << endl;
//             cout << "Updated postion from client side " << secondPlayer.getInput()->newPaddlePositions.y << endl;

//             packetToSend << gameDataTosend.clientPaddlePositions[0].x << gameDataTosend.clientPaddlePositions[0].y << gameDataTosend.playerScore[0];
//             client.sendGameData(packetToSend);

//             sf::Packet receivedPacket;
//             gameData gameDataToReceive;

//             client.receiveGameData(receivedPacket);
//             receivedPacket >> gameDataToReceive.clientPaddlePositions[0].x >> gameDataToReceive.clientPaddlePositions[0].y >> gameDataToReceive.clientPaddlePositions[1].x >> gameDataToReceive.clientPaddlePositions[1].y;
//             // std::cout << "Received paddle position from client: (" << clientPaddlePosition.x << ", " << clientPaddlePosition.y << ")\n";

//             secondPlayer.getPaddle()->setUpdatePosition(gameDataToReceive.clientPaddlePositions[0]);

//             firstPlayer.getPaddle()->setUpdatePosition(gameDataToReceive.clientPaddlePositions[1]); // update first-player

//             // update second player
//             ui->updateScore(firstPlayer.score, secondPlayer.score);            // Update the score ui
//             ball.check_ball_paddle_collision(ball, firstPlayer, secondPlayer); // check collisions

//             /*clear the screen */
//             window.clear();

//             /*drawing a object on screens*/
//             ui->drawFirstScore(window);
//             ui->drawSecondScore(window);
//             ui->drawGameStatus(window);
//             firstPlayer.draw(window);  // Draw a firstPlayer on game screen
//             secondPlayer.draw(window); // Draw a secondPlayer on game screen
//             ball.drawball(window);     // Draw a ball on screen
//             window.display();
//         }
//     }
//     else
//     {
//         cout << "Invalid choice;";
//     }
// }

// GameMode::~GameMode()
// {
// }
// int main()
// { /*Create a object of gameMode of and call constructor to start a game*/
//     GameMode game;

//     return 0;
// }

/*gameMode.cpp file and main method*/
#include "gameMode.hpp"

GameMode::GameMode()
{

    // Create an RPC object.
    RPC rpc;

    // Get the user's choice.
    std::string choice;
    std::cout << "Do you want to be the server (s) or the client (c)?" << std::endl;
    std::cin >> choice;

    // Set the RPC object's isServer flag.
    if (choice == "s")
    {
        rpc.isServer = true;
    }
    else
    {
        rpc.isServer = false;
    }

    // Start the server or client.
    if (rpc.isServer)
    {
        // Start the server socket.
        rpc.serverSocket.startListening(5500);
        rpc.serverSocket.acceptClient();

        // Accept a connection from the client.
    }
    else
    {
        // Connect to the server.
        std::string serverIP;
        unsigned short serverPort;

        std::cout << "Enter server IP: ";
        std::cin >> serverIP;
        std::cout << "Enter server port: ";
        std::cin >> serverPort;

        rpc.clientSocket.connectToServer(serverIP, serverPort);
        // rpc.clientSocket.connectToServer("localhost", 5500);
    }

    unsigned short framerate = 60.0f;

    unsigned short screen_width = sf::VideoMode::getDesktopMode().width;   // Get Desktop width
    unsigned short screen_height = sf::VideoMode::getDesktopMode().height; // Get Desktop height

    // screen_width = screen_width - 140;
    // screen_height = screen_height - 115;
    sf::RenderWindow window;

    /*  Arg->Argument
    Set the properties for Ball
    @param first-Arg set ball radius
    @param second-Arg set the ball position
    @param third-Arg set ball color
    */
    Ball ball(25.0f, Vector2f(screen_width / 2, screen_height / 2), sf::Color::Red);

    /*
      Set the properties for UserInterFace
      @param first-Arg argument set the char size
      @param second-Arg for set the color
      @param third parameter set the position
      */
    UserInterFace *ui = new UserInterFace(50, sf::Color::White, Vector2f(screen_width, screen_height));

    /*
    Set the properties for firstPlayer
    @param first-vector for set the postions
    @param second-vector for set the size
    @param third parameter set the color
    */
    Player firstPlayer(Vector2f(screen_width * 0, (screen_height / 2) - 125), Vector2f(25, 120), sf::Color::Green);

    Player secondPlayer(Vector2f(screen_width - 25, (screen_height / 2) - 125), Vector2f(25, 120), sf::Color::Green);

    if (rpc.isServer)
    {
        firstPlayer.setInputKey(sf::Keyboard::W, sf::Keyboard::S);
    }
    else
    {
        secondPlayer.setInputKey(sf::Keyboard::Up, sf::Keyboard::Down);
    }

    /*
      Set the properties for secondPlayer
      @param first-vector for set the postions
      @param second-vector for set the size
      @param third parameter set the color
      */

    /*Windows creted with screen_width and screen_height and in FullScreen mode*/ // sf::Style::Fullscreen
    if (rpc.isServer)
    {
        window.create(sf::VideoMode(screen_width, screen_height), "Server - Paddle Game");
    }
    else
    {
        window.create(sf::VideoMode(screen_width, screen_height), "Client - Paddle Game");
    }

    window.setFramerateLimit(framerate);

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            // Press escape for exit
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                window.close();
            }
        }

        /*
        Update a object with methods

        scree_width and screen_height for moving a ball across the window
        @param firstPlyer for the update the score
        @param secondPlayer for the update the score
        */

        ball.moveBall(screen_width, screen_height, firstPlayer, secondPlayer);

        // firstPlayer.updatePostion();

        firstPlayer.getInput()->update_paddle_position();

        secondPlayer.getInput()->update_paddle_position();

        // gameDataToSend.PlayerPaddlePositions[1].x = firstPlayer.getInput()->newPaddlePositions.x;
        // gameDataToSend.PlayerPaddlePositions[1].y = firstPlayer.getInput()->newPaddlePositions.y;
        if (rpc.isServer)
        {
            rpc.sendPaddlePosition(firstPlayer.getInput()->newPaddlePositions.x, firstPlayer.getInput()->newPaddlePositions.y);
        }
        else
        {
            rpc.sendPaddlePosition(secondPlayer.getInput()->newPaddlePositions.x, secondPlayer.getInput()->newPaddlePositions.y);
        }

        // secondPlayer.updatePostion();
        PaddlePosition paddlePosition = rpc.receivePaddlePosition();

        if (rpc.isServer)
            cout << "server - receiving-data is " << paddlePosition.x << "      " << paddlePosition.y << endl;
        else
            cout << "client - receiving-data is " << paddlePosition.x << "      " << paddlePosition.y << endl;

        if (!rpc.isServer)
        {
            secondPlayer.getPaddle()->setUpdatePosition(sf::Vector2f(secondPlayer.getInput()->newPaddlePositions.x, secondPlayer.getInput()->newPaddlePositions.y));
            firstPlayer.getPaddle()->setUpdatePosition(sf::Vector2f(paddlePosition.x, paddlePosition.y));
        }
        if (rpc.isServer)
        {
            firstPlayer.getPaddle()->setUpdatePosition(sf::Vector2f(firstPlayer.getInput()->newPaddlePositions.x, firstPlayer.getInput()->newPaddlePositions.y));
            secondPlayer.getPaddle()->setUpdatePosition(sf::Vector2f(paddlePosition.x, paddlePosition.y));
        }

        ui->updateScore(firstPlayer.score, secondPlayer.score);            // Update the score ui
        ball.check_ball_paddle_collision(ball, firstPlayer, secondPlayer); // check collisions

        /*clear the screen */
        window.clear();

        /*drawing a object on screens*/
        ui->drawFirstScore(window);
        ui->drawSecondScore(window);
        ui->drawGameStatus(window);
        firstPlayer.draw(window);  // Draw a firstPlayer on game screen
        secondPlayer.draw(window); // Draw a secondPlayer on game screen
        ball.drawball(window);     // Draw a ball on screen
        window.display();
    }
}

GameMode::~GameMode()
{
}
int main()
{ /*Create a object of gameMode of and call constructor to start a game*/
    GameMode game;

    return 0;
}