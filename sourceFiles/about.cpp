#include "../headerFiles/about.hpp"

About::About(sf::RenderWindow &newWindow) : window(newWindow)
{

    if (!aboutTexture.loadFromFile("../PaddleGame/assets/pictures/aboutt.jpeg"))
    {
        // Handle font loading error
        std::cerr << "image loading failed" << std::endl;
    }

    aboutSpirit.setTexture(aboutTexture);

    // aboutSpirit.setPosition(500, 500);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
               
                Menu menu(window);
                menu.run();
            }
        }

        // Clear the window
        window.clear();

        // Draw the input boxes

        window.draw(aboutSpirit);

        // Display everything
        window.display();
    }
}