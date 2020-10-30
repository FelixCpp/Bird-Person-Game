#pragma once

#include <BPG/Input/InputBinding.hpp>

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

#include <unordered_map>

namespace sf
{
	class Event;
}

namespace Input
{

	class InputManager {
	public:

		InputManager();

		void onEvent(const sf::Event & event);
		void listen();
		void clear();

		InputBinding & bind(sf::Keyboard::Key key);
		InputBinding & bind(sf::Mouse::Button button);
		MouseWheelBinding & bind(sf::Mouse::Wheel wheel);

	private:

		std::list<sf::Keyboard::Key> downKeys;
		std::list<sf::Mouse::Button> downButtons;

		std::unordered_map<sf::Keyboard::Key, InputBinding> keyBindings;
		std::unordered_map<sf::Mouse::Button, InputBinding> buttonBindings;
		std::unordered_map<sf::Mouse::Wheel, MouseWheelBinding> wheelBindings;

	};

}