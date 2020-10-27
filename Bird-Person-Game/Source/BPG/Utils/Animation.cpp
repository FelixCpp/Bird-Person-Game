#include <BPG/Utils/Animation.hpp>

namespace Utils
{

	Animation::Animation(const sf::Texture & texture, uint32_t cols, uint32_t rows, uint32_t startX, uint32_t lengthX, uint32_t startY, uint32_t lengthY) :
		holdTime(sf::milliseconds(100)),
		index(0u),
		texture(texture),
		frames()
	{
		const sf::Vector2u size = this->texture.getSize();
		const uint32_t tileWidth = size.x / cols;
		const uint32_t tileHeight = size.y / rows;

		for (uint32_t y = startY; y < startY + lengthY; y++)
		{
			for (uint32_t x = startX; x < startX + lengthX; x++)
			{
				const uint32_t xpos = x * tileWidth;
				const uint32_t ypos = y * tileHeight;
				this->frames.push_back(sf::IntRect(xpos, ypos, tileWidth, tileHeight));
			}
		}
	}

	void Animation::setHoldTime(const sf::Time & holdTime)
	{
		this->holdTime = holdTime;
	}

	void Animation::update(const sf::Time & deltaTime)
	{
		this->delay += deltaTime;
		if (this->delay >= this->holdTime)
		{
			this->delay = sf::Time::Zero;
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