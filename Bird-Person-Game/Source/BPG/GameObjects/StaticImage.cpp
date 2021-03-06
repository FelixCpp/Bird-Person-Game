#include <BPG/GameObjects/StaticImage.hpp>
#include <BPG/Utils/Loaders/ResourceLoader.hpp>

#include <iostream>

namespace GameObjects
{

	StaticImage::StaticImage(const std::string & filepath, float pixelScaleX, float pixelScaleY) :
		texture(Utils::Loaders::TextureLoader::get(filepath))
	{
		if (this->texture)
		{
			this->setTexture(*this->texture);

			const sf::Vector2u size = this->texture->getSize();
			this->setTextureRect(sf::IntRect(0, 0, size.x * pixelScaleX, size.y * pixelScaleY));
			this->texture->setRepeated(true);
		}
	}

	Maths::FVector2 StaticImage::getSize() const
	{
		const sf::IntRect boundary = this->getTextureRect();
		return Maths::FVector2(boundary.width, boundary.height);
	}

}