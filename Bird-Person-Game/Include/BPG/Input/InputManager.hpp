#pragma once

#include <BPG/Input/KeyBinding.hpp>

#include <SFML/Window/Keyboard.hpp>

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

		KeyBinding & bind(sf::Keyboard::Key key);

	private:

		std::list<sf::Keyboard::Key> downKeys;

		std::unordered_map<sf::Keyboard::Key, KeyBinding> bindings;

	};

}