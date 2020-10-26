#pragma once

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace GameObjects
{

	class View : public sf::View {

		inline static constexpr float SPEED = 900.f;

	public:

		explicit View(const sf::RenderWindow & window);

		void handleInput(const sf::Time & deltaTime);

	};

	typedef View Camera;

}