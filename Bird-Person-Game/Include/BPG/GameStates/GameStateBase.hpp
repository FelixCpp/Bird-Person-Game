#pragma once

#include <BPG/Input/InputManager.hpp>

namespace sf
{
	class Event;
	class Time;
	class RenderWindow;
}

namespace Utils
{
	class Application;
}

namespace GameStates
{

	class GameStateBase {
	public:

		explicit GameStateBase(Utils::Application & application);
		virtual ~GameStateBase();

		void onEvent(const sf::Event & event);
		
		virtual void update(const sf::Time & deltaTime) = 0;
		virtual void draw() const = 0;

	protected:

		Utils::Application & app;
		sf::RenderWindow & window;
		Input::InputManager input;

	};

}