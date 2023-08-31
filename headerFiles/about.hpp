#ifndef ABOUT_HPP
#define ABOUT_HPP
#include "../Library/SFML/include/SFML/Graphics.hpp"
#include"../MainMenu.hpp"
#include<iostream>
class About
{

public:
    About(sf::RenderWindow & newWindow);

private:
    sf::RenderWindow &window;
    sf::Texture aboutTexture;
    sf::Sprite aboutSpirit;
    sf::Font m_font;
};

#endif // ABOUT_HPP