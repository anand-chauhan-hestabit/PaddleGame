/*gameMode.cpp file and main method*/
#include "../headerFiles/online.hpp"

OnlineMode::OnlineMode(sf::RenderWindow &newWindow) : window(newWindow)
{
    // Create an RPC object.
    RPC rpc;

    // Get the user's choice.
    std::string choice;
    std::cout << "Do you want to be the server (s) or the client (any key)?" << std::endl;
    std::cin >> choice;

    // Set the RPC object's isServer flag.
    if (choice == "s" || choice == "S")
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
        cout << "server is listening for connectios " << endl;
        rpc.serverSocket.acceptClient();
        cout << "server is connected with client " << endl;
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

        if (!rpc.clientSocket.isServerConnected)
        {
            cout << "not Connected to server " << endl;
            return;
        }
        cout << "Client is connected with server " << endl;
    }

    unsigned short framerate = 60.0f;

    unsigned short screen_width = sf::VideoMode::getDesktopMode().width;   // Get Desktop width
    unsigned short screen_height = sf::VideoMode::getDesktopMode().height; // Get Desktop height

    // screen_width = screen_width - 140;
    // screen_height = screen_height - 115;
    // sf::RenderWindow window;

    /*  Arg->Argument
    Set the properties for Ball
    @param first-Arg set ball radius
    @param second-Arg set the ball position
    @param third-Arg set ball color
    */
    Ball ball(25.0f, Vector2f(screen_width / 2, screen_height / 2), sf::Color::Yellow);

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
    /*
    Set the properties for secondPlayer
    @param first-vector for set the postions
    @param second-vector for set the size
    @param third parameter set the color
          */
    Player secondPlayer(Vector2f(screen_width - 25, (screen_height / 2) - 125), Vector2f(25, 120), sf::Color::Red);

    /*Set he method to acording client and server*/
    if (rpc.isServer) /*If choose a server */
    {
        firstPlayer.setInputKey(sf::Keyboard::W, sf::Keyboard::S);
    }
    else /*Else conditions */
    {
        secondPlayer.setInputKey(sf::Keyboard::Up, sf::Keyboard::Down);
    }

    /*Windows creted with screen_width and screen_height and in FullScreen mode*/ // sf::Style::Fullscreen
    if (rpc.isServer)                                                             /*If choose a server*/
    {
        window.create(sf::VideoMode(screen_width, screen_height), "Server - Paddle Game");
    }
    else /*If not choose a server*/
    {
        window.create(sf::VideoMode(screen_width, screen_height), "Client - Paddle Game");
    }

    window.setFramerateLimit(framerate); /*same framerate for both system*/
    GameState gameState;                 /*Declare a GameState (Struct)*/

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            // Press escape for exit
            // else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            // {
            //     window.close();
            // }
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {

                Menu menu(window);
                menu.run();
                std::cout << "escaped clicked" << endl;
            }
        }

        /*
        Update a object with methods

        scree_width and screen_height for moving a ball across the window
        @param firstPlyer for the update the score
        @param secondPlayer for the update the score
        */

        if (rpc.isServer)
        {
            ball.moveBall(firstPlayer, secondPlayer);
            firstPlayer.updatingInput();
            ball.setBallPosition(ball.getBallPosition());
            gameState.paddlePosition = firstPlayer.getPlayerPosistion();
            gameState.ballPosition = ball.getBallPosition();
            gameState.score[0] = firstPlayer.score;
            gameState.score[1] = secondPlayer.score;
            // cout << " server- fist score is " << firstPlayer.score << " second score is " << secondPlayer.score << endl;

            rpc.sendGameState(gameState);
        }
        else
        {
            secondPlayer.updatingInput();
            gameState.paddlePosition = secondPlayer.getPlayerPosistion();
            rpc.sendGameState(gameState);
        }

        gameState = rpc.receiveGameState();

        if (!rpc.isServer)
        {
            ball.setBallPosition(gameState.ballPosition);
            // secondPlayer.getPaddle()->setUpdatePosition(sf::Vector2f(secondPlayer.getInput()->newPaddlePositions.x, secondPlayer.getInput()->newPaddlePositions.y));
            secondPlayer.setPlayerPositons(secondPlayer.getPlayerPosistion());

            firstPlayer.setPlayerPositons(gameState.paddlePosition);
            firstPlayer.score = gameState.score[0];
            secondPlayer.score = gameState.score[1];
            // cout << " clinet- fist score is " << firstPlayer.score << " second score is " << secondPlayer.score << endl;
        }
        if (rpc.isServer)
        {
            // firstPlayer.getPaddle()->setUpdatePosition(sf::Vector2f(firstPlayer.getInput()->newPaddlePositions.x, firstPlayer.getInput()->newPaddlePositions.y));
            firstPlayer.setPlayerPositons(firstPlayer.getPlayerPosistion());
            secondPlayer.setPlayerPositons(gameState.paddlePosition);
        }

        ui->updateScore(firstPlayer.score, secondPlayer.score, "Online", sf::Color::Green);

        // Update the score ui
        ball.check_ball_paddle_collision(ball, firstPlayer, secondPlayer); // check collisions

        /*clear the screen */
        window.clear();

        /*drawing a object on screens*/
        ui->drawFirstScore(window);
        ui->drawSecondScore(window);
        ui->drawGameStatus(window);
        ui->drawScoreImage(window);

        ui->drawServerStatus(window);
        ui->drawClientStatus(window);

        firstPlayer.draw(window);  // Draw a firstPlayer on game screen
        secondPlayer.draw(window); // Draw a secondPlayer on game screen
        ball.drawball(window);     // Draw a ball on screen
        window.display();
    }
}

OnlineMode::~OnlineMode()
{
}
