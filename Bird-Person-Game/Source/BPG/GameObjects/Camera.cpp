#include <BPG/GameObjects/Camera.hpp>

#include <SFML/Window/Keyboard.hpp>

namespace GameObjects
{

	Camera::Camera(const sf::RenderWindow & window) :
		View(sf::Vector2f(0.f, 0.f), (sf::Vector2f)window.getSize())
	{
	}

	void Camera::handleInput(const sf::Time & deltaTime)
	{
		sf::Vector2f velocity(0.f, 0.f);

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

		this->move(velocity * SPEED * deltaTime.asSeconds());
	}

}