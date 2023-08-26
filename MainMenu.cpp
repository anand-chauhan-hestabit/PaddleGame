#include "MainMenu.hpp"

Menu::Menu(sf::RenderWindow &window) : m_window(window), m_selectedItemIndex(0)
{
    m_backgroundTexture.loadFromFile("/home/hestabit/Desktop/PaddleGame/assets/pictures/img.jpg"); // Update with your image path
    m_background.setTexture(m_backgroundTexture);

    m_font.loadFromFile("/home/hestabit/Desktop/PaddleGame/assets/fonts/english.ttf"); // Update with your font path

    const std::string menuStrings[4] = {"Online", "Offline", "About", "Exit"};
    for (int i = 0; i < 4; ++i)
    {
        m_menuText[i].setFont(m_font);
        m_menuText[i].setString(menuStrings[i]);
        m_menuText[i].setCharacterSize(50);
        m_menuText[i].setPosition(500, 100 * i + 50);
    }
}

bool Menu::isMouseOverText(sf::Text &text)
{
    sf::FloatRect bounds = text.getGlobalBounds();
    sf::Vector2i mousePosition = sf::Mouse::getPosition(m_window);
    return bounds.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
}

void Menu::updateTextColors()
{
    for (int i = 0; i < 4; ++i)
    {
        if (isMouseOverText(m_menuText[i]))
        {
            m_menuText[i].setFillColor(sf::Color::Red); // Change color on hover
        }
        else
        {
            m_menuText[i].setFillColor(sf::Color::White); // Default color
        }
    }
}

void Menu::run()
{
    while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                m_window.close();
            }

            // Handle mouse move event
            if (event.type == sf::Event::MouseMoved)
            {
                updateTextColors(); // Update text colors on mouse move
            }

            // Handle mouse click event
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    for (int i = 0; i < 4; ++i)
                    {
                        if (isMouseOverText(m_menuText[i]))
                        {

                            if (i == 0)
                            {
                                m_window.close();
                                online = new OnlineMode();
                            }
                            if (i == 1)
                            {
                                m_window.close();
                                offline = new OfflineMode();
                            }
                            if (i == 3)
                            {
                                m_window.close(); // Exit option clicked
                            }

                            else
                            {
                                // Handle other menu options
                            }
                        }
                    }
                }
            }
        }

        m_window.clear();
        m_window.draw(m_background);
        for (int i = 0; i < 4; ++i)
        {
            m_window.draw(m_menuText[i]);
        }
        m_window.display();
    }
}

// Main method for run the game

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 600), "SFML Menu Example");
    window.setFramerateLimit(60); // Limit the frame rate to prevent high CPU usage

    Menu menu(window);
    menu.run();

    return 0;
}
