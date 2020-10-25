#pragma once

#include <vector>
#include <string>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Time.hpp>

namespace Utils
{

	class Animation {
	public:

		explicit Animation(const sf::Texture & texture, size_t cols, size_t rows, size_t startX, size_t lengthX, size_t startY, size_t lengthY);

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