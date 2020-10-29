#include <BPG/Input/InputManager.hpp>

#include <SFML/Window/Event.hpp>
#include <iostream>

namespace Input
{
	
	InputManager::InputManager() :
		bindings()
	{
	}

	void InputManager::onEvent(const sf::Event & event)
	{
		switch (event.type)
		{
			case sf::Event::KeyPressed:
			{
				const sf::Event::KeyEvent & args = event.key;
				this->downKeys.push_back(args.code);

				for (const auto&[key, binding] : this->bindings)
				{
					if (args.code == key)
					{
						binding.invokeKeyPressed();
					}
				}
			} break;

			case sf::Event::KeyReleased:
			{
				const sf::Event::KeyEvent & args = event.key;
				this->downKeys.remove(args.code);

				for (const auto&[key, binding] : this->bindings)
				{
					if (event.key.code == key)
					{
						binding.invokeKeyReleased();
					}
				}
			} break;

			default:
				break;
		}
	}

	void InputManager::listen()
	{
		for (const auto & [key, binding] : this->bindings)
		{
			for (const auto & down : this->downKeys)
			{
				if (key == down)
				{
					binding.invokeKeyDown();
				}
			}
		}
	}

	void InputManager::clear()
	{
		this->bindings.clear();
	}

	KeyBinding & InputManager::bind(sf::Keyboard::Key key)
	{
		return this->bindings[key];
	}

}