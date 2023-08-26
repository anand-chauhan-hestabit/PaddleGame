#pragma once
#include </home/hestabit/Desktop/PaddleGame/Library/SFML/include/SFML/Graphics.hpp>
#include <iostream>

class Menu {
public:
    Menu(sf::RenderWindow& window);

    void run();

private:
    sf::RenderWindow& m_window;
    sf::Texture m_backgroundTexture;
    sf::Sprite m_background;
    sf::Font m_font;
    sf::Text m_menuText[4]; // Array for menu text
    int m_selectedItemIndex;

    bool isMouseOverText(sf::Text& text);
    void updateTextColors();
    void updateTextLayout(); // New method for updating text positions and sizes
};

