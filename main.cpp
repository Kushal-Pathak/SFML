#include<SFML/Graphics.hpp>
#include <iostream>

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 800), "My Window");
	sf::Texture texture;
	sf::Sprite sprite;
	if (!texture.loadFromFile("img.jpg")) {
		std::cout << "Error loading image" << std::endl;
	}
	sprite.setTexture(texture);
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.clear(sf::Color::Black);
		window.draw(sprite);
		window.display();
	}
}
