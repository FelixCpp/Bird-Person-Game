#include <BPG/Utils/Animation.hpp>

namespace Utils
{

	Animation::Animation(const sf::Texture & texture, size_t cols, size_t rows, size_t startX, size_t lengthX, size_t startY, size_t lengthY) :
		holdTime(sf::milliseconds(100)),
		index(0u),
		texture(texture),
		frames()
	{
		const sf::Vector2u size = this->texture.getSize();
		const uint32_t tileWidth = size.x / cols;
		const uint32_t tileHeight = size.y / rows;

		for (size_t y = startY; y < startY + lengthY; y++)
		{
			for (size_t x = startX; x < startX + lengthX; x++)
			{
				const uint32_t xpos = x * tileWidth;
				const uint32_t ypos = y * tileHeight;
				this->frames.push_back(sf::IntRect(xpos, ypos, tileWidth, tileHeight));
			}
		}
	}

	void Animation::update()
	{
		if (this->clock.getElapsedTime() >= this->holdTime)
		{
			this->clock.restart();
			this->advance();
		}
	}

	void Animation::applyToSprite(sf::Sprite & sprite)
	{
		sprite.setTexture(this->texture);
		sprite.setTextureRect(this->frames[this->index]);
	}

	void Animation::advance()
	{
		this->index++;
		if (this->index >= this->frames.size())
		{
			this->index = 0;
		}
	}

}