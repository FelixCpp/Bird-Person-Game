#pragma once

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace GameObjects
{

	class Camera : public sf::View {

		inline static constexpr float SPEED = 800.f;

	public:

		explicit Camera(const sf::RenderWindow & window);

		void handleInput(const sf::Time & deltaTime);

	};

}