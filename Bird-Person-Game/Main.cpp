#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/CircleShape.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "Welcome to SFML");
	window.setFramerateLimit(60);

	sf::CircleShape circle(100.f);
	circle.setFillColor(sf::Color::Green);

	sf::Event event;
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::Closed)
				window.close();
		}

		window.clear();
		window.draw(circle);
		window.display();
	}

	return EXIT_SUCCESS;
}