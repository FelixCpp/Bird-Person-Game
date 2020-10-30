#pragma once

#include <memory>

#include <BPG/Maths/Vector2.hpp>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace GameObjects
{

	class StaticImage : public sf::Sprite {
	public:

		explicit StaticImage(const std::string & filepath, float pixelScaleX, float pixelScaleY);

		Maths::FVector2 getSize() const;

	private:

		std::shared_ptr<sf::Texture> texture;

	};

}