#include <BPG/Extensions/View.hpp>
#include <BPG/Extensions/Vector2.hpp>

#include <SFML/Window/Keyboard.hpp>

namespace GameObjects
{

	View::View(const sf::RenderWindow & window) :
		sf::View(sf::Vector2f(0.f, 0.f), (sf::Vector2f)window.getSize())
	{
	}

	void View::handleInput(const sf::Time & deltaTime)
	{
		Maths::Vector2f velocity(0.f, 0.f);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
		{
			velocity.y = -1.f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
		{
			velocity.y = 1.f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		{
			velocity.x = -1.f;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		{
			velocity.x = 1.f;
		}

		velocity.setLength(SPEED * deltaTime.asSeconds());
		this->move(velocity);
	}

}