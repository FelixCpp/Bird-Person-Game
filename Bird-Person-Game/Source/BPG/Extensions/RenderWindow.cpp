#include <BPG/Extensions/RenderWindow.hpp>
#include <BPG/Utils/Loaders/ResourceLoader.hpp>

#include <iostream>

namespace Extensions
{

	RenderWindow::RenderWindow(const sf::VideoMode & mode, const std::string & title, uint32_t style, const sf::ContextSettings & settings) :
		sf::RenderWindow(mode, title, style, settings),
		cursor()
	{
		this->initializeComponents();
	}

	void RenderWindow::initializeComponents()
	{
		this->updateCursor();
		this->updateIcon();
	}

	void RenderWindow::updateCursor()
	{
		if (auto cursorImage = Utils::Loaders::ImageLoader::get("Assets/Cursors/Aerowedge.png"))
		{
			const sf::Uint8 * pixels = cursorImage->getPixelsPtr();
			const sf::Vector2u size = cursorImage->getSize();

			if (this->cursor.loadFromPixels(pixels, size, sf::Vector2u()))
			{
				this->setMouseCursor(this->cursor);
			}
		}
	}

	void RenderWindow::updateIcon()
	{
		if (auto iconImage = Utils::Loaders::ImageLoader::get("Assets/Icons/GameIcon.png"))
		{
			const sf::Uint8 * pixels = iconImage->getPixelsPtr();
			const sf::Vector2u size = iconImage->getSize();

			if (pixels)
			{
				this->setIcon(size.x, size.y, pixels);
			}
		}
	}

}