#include <BPG/Extensions/View.hpp>
#include <BPG/Maths/Vector2.hpp>

#include <SFML/Window/Keyboard.hpp>
#include <BPG/Input/InputManager.hpp>

namespace Extensions
{

	View::View(const sf::RenderWindow & window) :
		sf::View((sf::Vector2f)window.getSize() / 2.f, (sf::Vector2f)window.getSize()),
		velocity(0.f, 0.f)
	{
	}

	void View::bindInput(Input::InputManager & input)
	{
		input.bind(sf::Keyboard::Down).onDown([this]() { this->velocity.y = 1.f; });
		input.bind(sf::Keyboard::Up).onDown([this]() { this->velocity.y = -1.f; });
		input.bind(sf::Keyboard::Right).onDown([this]() { this->velocity.x = 1.f; });
		input.bind(sf::Keyboard::Left).onDown([this]() { this->velocity.x = -1.f; });
	}

	void View::update(const sf::Time & deltaTime)
	{
		this->velocity.setLength(SPEED * deltaTime.asSeconds());
		this->move(this->velocity.toSFVector2());
		this->velocity *= 0.f;
	}

}