#pragma once
#include </home/hestabit/Desktop/PaddleGame/Library/SFML/include/SFML/Graphics.hpp>
#include <iostream>
class input
{
public:
    input();
};
input::input()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Input Box Example");
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("/home/hestabit/Desktop/PaddleGame/arial_narrow.ttf"))
    { // Load your font
        
    }

    sf::Text inputText;
    inputText.setFont(font);
    inputText.setCharacterSize(30);
    inputText.setFillColor(sf::Color::White);

    sf::RectangleShape inputBox(sf::Vector2f(300, 50));
    inputBox.setFillColor(sf::Color::Black);
    inputBox.setOutlineThickness(2);
    inputBox.setOutlineColor(sf::Color::White);
    inputBox.setPosition(250, 250);

    std::string ipInput;
    std::string portInput;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            // Handle text input
            if (event.type == sf::Event::TextEntered)
            {
                if (event.text.unicode < 128 && event.text.unicode != '\b')
                {
                    if (ipInput.size() < 15)
                    { // Limit IP input to 15 characters
                        ipInput += static_cast<char>(event.text.unicode);
                    }
                }
                else if (event.text.unicode == '\b' && !ipInput.empty())
                {
                    ipInput.pop_back(); // Handle backspace
                }
            }
        }

        // Clear the window
        window.clear();

        // Draw the input box
        window.draw(inputBox);

        // Set inputText's string and position
        inputText.setString(ipInput);
        inputText.setPosition(265, 255);
        window.draw(inputText);

        // Display everything
        window.display();
    }
}
