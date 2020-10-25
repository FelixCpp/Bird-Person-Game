#include <BPG/Utils/Animation.hpp>

namespace Utils
{

	Animation::Animation(const sf::Texture & texture, size_t cols, size_t rows, size_t startX, size_t lengthX, size_t startY, size_t lengthY) :
		delay(sf::Time::Zero),
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

	void Animation::Update(const sf::Time & deltaTime)
	{
		this->delay += deltaTime;
		if (this->delay >= this->holdTime)
		{
			this->delay = sf::Time::Zero;
			this->Advance();
		}
	}

	void Animation::ApplyToSprite(sf::Sprite & sprite)
	{
		sprite.setTexture(this->texture);
		sprite.setTextureRect(this->frames[this->index]);
	}

	void Animation::Advance()
	{
		this->index++;
		if (this->index >= this->frames.size())
		{
			this->index = 0;
		}
	}

}