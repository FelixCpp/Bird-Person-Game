#pragma once

#include <memory>

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>

namespace GameObjects
{

	class FrameRateCounter : public sf::Text {
	public:

		FrameRateCounter();

		void count();

		void setRefreshRate(const sf::Time & refreshRate);
		const sf::Time & getRefreshRate() const;

		float getFps() const;

	private:

		std::shared_ptr<sf::Font> font;

		sf::Time refreshRate;

		sf::Clock delayClock;
		sf::Clock fpsClock;

		uint32_t frameCount;
		float fps;

	};

}