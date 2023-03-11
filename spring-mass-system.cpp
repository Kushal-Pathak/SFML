#include<SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#define height 900
#define width 1200

sf::Vector2f block;
float e = 100, e2=300, m = 100, v = 0, a = 0, f = 0,f2=0,v2,a2,m2=100, k = 10, y_1 = height / 2.f, y2 = y_1 + e, g = 1, y3 = y2 + e2;
void update();
int main() {
	
	sf::RenderWindow window(sf::VideoMode(width, height), "My Window");
	sf::CircleShape c1;
	sf::CircleShape c2;
	sf::CircleShape c3;
	c1.setRadius(10.f);
	c2.setRadius(50.f);
	c3.setRadius(50.f);
	c1.setPosition((width / 2), 50);
	c1.setOrigin(c1.getRadius(), c1.getRadius());
	c2.setPosition((width / 2), height / 2);
	c2.setOrigin(c2.getRadius(), c2.getRadius());
	c3.setPosition((width / 2), (height / 2)+300);
	c3.setOrigin(c3.getRadius(), c3.getRadius());
	c2.setFillColor(sf::Color::Red);
	c3.setFillColor(sf::Color::Green);
	sf::Vertex line[] = {
		sf::Vector2f(c1.getPosition()),
		sf::Vector2f(c2.getPosition())
	};
	sf::Vertex line2[] = {
		sf::Vector2f(c2.getPosition()),
		sf::Vector2f(c3.getPosition())
	};


	while (window.isOpen()) {
		update();
		c2.setPosition(width / 2, y2);
		line[1] = sf::Vector2f(c2.getPosition());
		c3.setPosition(width / 2, y3);
		line2[0] = sf::Vector2f(c2.getPosition());
		line2[1] = sf::Vector2f(c3.getPosition());
		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		Sleep(100);
		window.clear(sf::Color::Black);
		window.draw(line, 2, sf::Lines);
		window.draw(line2, 2, sf::Lines);
		window.draw(c2);
		window.draw(c1);
		window.draw(c3);
		window.display();
	}
}

void update() {
	f = -k * e;
	a = f / m;
	v = v + a;
	y2 = y2 + v;
	e = y2 - y_1;
	v *= 0.975f;

	f2 = -k * e2;
	a2 = f2 / m2;
	v2 = v2 + a2;
	y3 = y3 + v2;
	e2 = (height/2) - y2;
	v2 *= 0.5f;
}
