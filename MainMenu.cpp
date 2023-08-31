#include "MainMenu.hpp"

Menu::Menu(sf::RenderWindow &window) : m_window(window), m_selectedItemIndex(0)
{  
    m_backgroundTexture.loadFromFile("assets/pictures/img.jpg"); // Update with your image path
    m_background.setTexture(m_backgroundTexture);
    m_background.scale(2, 2);

    m_font.loadFromFile("assets/fonts/english.ttf"); // Update with your font path

    const std::string menuStrings[4] = {"Online", "Offline", "About", "Exit"};
    for (int i = 0; i < 4; ++i)
    {
        m_menuText[i].setFont(m_font);
        m_menuText[i].setString(menuStrings[i]);
        m_menuText[i].setCharacterSize(50);
        m_menuText[i].setPosition(sf::VideoMode::getDesktopMode().width / 2 - m_menuText[i].getPosition().x / 2, sf::VideoMode::getDesktopMode().height / 7 * i + 10);
    }
    gameStartSound.playSound("gameStart");
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
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
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
                                m_menuText[i].setString("Online clicked");
                                m_menuText[i + 1].setString("Server");
                                m_menuText[i + 2].setString("Client");
                            }
                            else if (i == 1)
                            {
                                // Play offline
                                if (i == 1 && m_menuText[i].getString() == "Server")
                                {
                                    m_menuText[i].setString("Server is listening...");
                                    m_window.close();
                                    OnlineMode online(m_window);
                                }

                                else
                                {
                                    // m_menuText[i].setString("Offline clicked");
                                    // m_window.close();
                                    gameStartSound.pauseSound("gameStart");
                                    OfflineMode offline(m_window);
                                }
                            }
                            else if (i == 2)
                            {
                                if (i == 2 && m_menuText[i].getString() == "Client")
                                {
                                    // m_menuText[i].setString("client clicked");
                                    m_window.close();
                                    OnlineMode online(m_window);
                                }

                                else
                                {
                                    m_menuText[i].setString("about clicked");
                                    About about(m_window);
                                }
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
    unsigned short screen_width = sf::VideoMode::getDesktopMode().width;   // Get Desktop width
    unsigned short screen_height = sf::VideoMode::getDesktopMode().height; // Get Desktop height

    sf::RenderWindow window(sf::VideoMode(screen_width, screen_height), "Main Menu");
    window.setFramerateLimit(60); // Limit the frame rate to prevent high CPU usage

    Menu menu(window);
    menu.run();

    return 0;
}
