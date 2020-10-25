#pragma once

#include <memory>

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>

#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>

namespace GameObjects
{

	class FrameRateCounter : public sf::Drawable, public sf::Transformable {
	public:

		FrameRateCounter();

		void Count();

		void SetRefreshRate(const sf::Time & refreshRate);
		const sf::Time & GetRefreshRate() const;

		float GetFps() const;

	protected:

		virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

	private:

		sf::Text text;
		std::shared_ptr<sf::Font> font;

		sf::Time refreshRate;

		sf::Clock delayClock;
		sf::Clock fpsClock;

		uint32_t frameCount;
		float fps;

	};

}