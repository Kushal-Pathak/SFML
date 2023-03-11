#include<SFML/Graphics.hpp>
#include <iostream>

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "My Window");
	
	sf::CircleShape circle(50.0f);
	circle.setPosition(100.f, 100.f);
	circle.move(200.f, 200.f);
	sf::Vector2f position = circle.getPosition();
	std::cout << "x: " << position.x << " y: " << position.y << std::endl;
	circle.setFillColor(sf::Color::Green);
	circle.setOutlineThickness(10.0f);
	circle.setOutlineColor(sf::Color::Red);
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.clear(sf::Color::Black);
		window.draw(circle);
		window.display();
	}
}
