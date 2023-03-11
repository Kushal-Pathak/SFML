#include<SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#define height 900
#define width 1200

sf::Vector2f block;
float e = 100, m = 100, v = 0, a = 0, f = 0, k = 20, y_1 = height / 2, y2 = y_1 + e, g=1, gf;
void update();
int main() {
	
	sf::RenderWindow window(sf::VideoMode(width, height), "My Window");
	sf::CircleShape c1;
	sf::CircleShape c2;
	c1.setRadius(20.f);
	c2.setRadius(50.f);
	c1.setPosition((width / 2)+20.f, 10);
	c2.setPosition((width / 2)+50.f, height / 2);
	sf::Vertex line[] = {
		sf::Vector2f(c1.getPosition().x + c1.getRadius(), c1.getPosition().y + c1.getRadius()),
		sf::Vector2f(c2.getPosition().x + c2.getRadius(), c2.getPosition().y + c2.getRadius())
	};


	while (window.isOpen()) {
		update();
		c2.setPosition(width / 2, y2);
		line[1] = sf::Vector2f(c2.getPosition().x + c2.getRadius(), c2.getPosition().y + c2.getRadius());
		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		Sleep(100);
		window.clear(sf::Color::Black);
		window.draw(c2);
		window.draw(c1);
		window.draw(line, 2, sf::Lines);
		window.display();
	}
}

void update() {
	gf = m * g;
	f = -k * e;
	a = f / m;
	v = v + a;
	y2 = y2 + v;
	e = y2 - y_1;
}
