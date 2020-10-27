#pragma once

#include <vector>
#include <string>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>

namespace Utils
{

	class Animation {
	public:

		explicit Animation(const sf::Texture & texture, uint32_t cols, uint32_t rows, uint32_t startX, uint32_t lengthX, uint32_t startY, uint32_t lengthY);

		void setHoldTime(const sf::Time & holdTime);
		
		void update(const sf::Time & deltaTime);
		void applyToSprite(sf::Sprite & sprite);

	private:

		void advance();
		
	private:

		sf::Time delay;
		sf::Time holdTime;

		uint32_t index;
		sf::Texture texture;

		std::vector<sf::IntRect> frames;

	};

}