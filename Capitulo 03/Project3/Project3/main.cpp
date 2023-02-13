#include <SFML/Graphics.hpp> // replace quotes with less than and greater than symbols

int main()
{
	sf::Vector2f viewSize(1280, 720);
	sf::VideoMode videoMode(viewSize.x, viewSize.y);
	sf::RenderWindow window(videoMode, "Janela", sf::Style::Default);
	sf::RectangleShape rect(sf::Vector2f(600.0f, 400.0f));
	rect.setFillColor(sf::Color::Green);
	rect.setPosition(viewSize.x / 2, viewSize.y / 2);
	rect.setOrigin(sf::Vector2f(rect.getSize().x / 2, rect.getSize().y / 2));
	sf::CircleShape circle(100);
	circle.setFillColor(sf::Color::Blue);
	circle.setPosition(viewSize.x / 2, viewSize.y / 2);
	circle.setOrigin(sf::Vector2f(circle.getRadius(),
		circle.getRadius()));
	sf::ConvexShape losang;
	losang.setPointCount(4);
	losang.setPoint(0, sf::Vector2f(-250, 0));
	losang.setPoint(1, sf::Vector2f(0, -150));
	losang.setPoint(2, sf::Vector2f(250, 0));
	losang.setPoint(3, sf::Vector2f(0, 150));
	losang.setFillColor(sf::Color(255, 255, 0, 255));
	losang.setPosition(viewSize.x / 2, viewSize.y / 2);

	sf::Event event;
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			window.clear(sf::Color::Black);
			// Render Game Objects
			window.draw(rect);
			window.draw(losang);
			window.draw(circle);

			window.display();
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
	}
	return 0;
}