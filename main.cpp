#include <iostream>
#include <SFML/Graphics.hpp>
#include "sfml_gui.hpp"

int main () {
	sf::RenderWindow window(sf::VideoMode(600, 400), "Test", sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(30);

	sf::GUI::Button button;
	button.setText("OK");
	button.setSize(sf::Vector2f(200, 100));
	button.setPosition(sf::Vector2f(10, 50));
	button.setBackgroundColor(sf::Color(201, 201, 201));
	button.setTextColor(sf::Color(38, 38, 38));
	sf::Font font;
	if (!font.loadFromFile("arial.ttf")) {
		std::cerr << "[!] Cannot load font." << std::endl;
		return 1;
	}
	button.setTextFont(font);
	button.setBackgroundColorHover(sf::Color(173, 173, 173));
	button.setTextColorHover(sf::Color(38, 38, 38));
	button.setOutlineThickness(2);
	button.setOutlineColor(sf::Color(38, 38, 38));
	button.setOutlineColorHover(sf::Color(38, 38, 38));
	button.setCharacterSize(20);
	button.setBackgroundColorClicked(sf::Color(100, 100, 100));

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::MouseMoved:
					button.onHover(event.mouseMove.x, event.mouseMove.y);
					break;
				case sf::Event::MouseButtonPressed:
					if (button.isOnHover())
						button.onClick();
					break;
				case sf::Event::MouseButtonReleased:
					if (button.isOnHover())
						button.onRelease();
					break;
				default:
					break;
			}
		}
		window.clear();
		window.draw(button);
		window.display();
	}


	return 0;
}