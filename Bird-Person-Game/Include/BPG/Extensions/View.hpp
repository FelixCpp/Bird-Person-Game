#pragma once

#include <BPG/Maths/Vector2.hpp>

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace Input
{
	class InputManager;
}

namespace Extensions
{

	class View : public sf::View {

		inline static constexpr float SPEED = 900.f;

	public:

		explicit View(const sf::RenderWindow & window);

		void bindInput(Input::InputManager & input);
		void update(const sf::Time & deltaTime);

	private:

		Maths::FVector2 velocity;

	};

	typedef View Camera;

}