#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 700), "Welcome to SFML");
	window.setFramerateLimit(60);

	sf::Event event;
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::Closed)
				window.close();
		}

		window.clear();

		window.display();
	}

	return EXIT_SUCCESS;
}