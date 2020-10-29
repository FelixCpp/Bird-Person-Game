#pragma once

#include <memory>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace GameObjects
{

	class StaticImage : public sf::Sprite {
	public:

		explicit StaticImage(const std::string & filepath, float pixelScaleX, float pixelScaleY);

	private:

		std::shared_ptr<sf::Texture> texture;

	};

}