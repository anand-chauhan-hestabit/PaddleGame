#include </home/hestabit/Desktop/PaddleGame/Library/SFML/include/SFML/Graphics.hpp>
#include"MainMenu.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(1000, 600), "SFML Menu Example");
    window.setFramerateLimit(60); // Limit the frame rate to prevent high CPU usage

    Menu menu(window);
    menu.run();

    return 0;
}
