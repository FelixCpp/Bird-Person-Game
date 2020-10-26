#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

namespace Extensions
{

	class RenderWindow : public sf::RenderWindow {
	public:

		explicit RenderWindow(const sf::VideoMode & mode, const std::string & title, uint32_t style, const sf::ContextSettings & settings = sf::ContextSettings());

	};

}