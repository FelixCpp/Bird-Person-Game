#include <BPG/Input/InputManager.hpp>

#include <SFML/Window/Event.hpp>
#include <iostream>

namespace Input
{
	
	InputManager::InputManager() :
		keyBindings(),
		buttonBindings()
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

				for (const auto & [key, binding] : this->keyBindings)
				{
					if (args.code == key)
					{
						binding.invokePressed();
					}
				}
			} break;

			case sf::Event::KeyReleased:
			{
				const sf::Event::KeyEvent & args = event.key;
				this->downKeys.remove(args.code);

				for (const auto & [key, binding] : this->keyBindings)
				{
					if (event.key.code == key)
					{
						binding.invokeReleased();
					}
				}
			} break;

			case sf::Event::MouseButtonPressed:
			{
				const sf::Event::MouseButtonEvent & args = event.mouseButton;
				this->downButtons.push_back(args.button);

				for (const auto & [button, binding] : this->buttonBindings)
				{
					if (args.button == button)
					{
						binding.invokePressed();
					}
				}
			} break;

			case sf::Event::MouseButtonReleased:
			{
				const sf::Event::MouseButtonEvent & args = event.mouseButton;
				this->downButtons.remove(args.button);

				for (const auto & [button, binding] : this->buttonBindings)
				{
					if (args.button == button)
					{
						binding.invokeReleased();
					}
				}
			} break;

			case sf::Event::MouseWheelScrolled:
			{
				const sf::Event::MouseWheelScrollEvent & args = event.mouseWheelScroll;
				
				for (const auto & [wheel, binding] : this->wheelBindings)
				{
					if (args.wheel == wheel)
					{
						binding.invokeChange(args.delta);
					}
				}
			} break;

			default:
				break;
		}
	}

	void InputManager::listen()
	{
		for (const auto & [key, binding] : this->keyBindings)
		{
			for (const auto & down : this->downKeys)
			{
				if (key == down)
				{
					binding.invokeDown();
				}
			}
		}

		for (const auto & [button, binding] : this->buttonBindings)
		{
			for (const auto & down : this->downButtons)
			{
				if (button == down)
				{
					binding.invokeDown();
				}
			}
		}
	}

	void InputManager::clear()
	{
		this->keyBindings.clear();
		this->buttonBindings.clear();
	}

	InputBinding & InputManager::bind(sf::Keyboard::Key key)
	{
		return this->keyBindings[key];
	}

	InputBinding & InputManager::bind(sf::Mouse::Button button)
	{
		return this->buttonBindings[button];
	}

	MouseWheelBinding & InputManager::bind(sf::Mouse::Wheel wheel)
	{
		return this->wheelBindings[wheel];
	}

}