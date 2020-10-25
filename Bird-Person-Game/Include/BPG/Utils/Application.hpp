#pragma once

#include <stack>
#include <memory>
#include <string>

#include <SFML/Graphics/RenderWindow.hpp>

#include <BPG/GameStates/GameStateBase.hpp>

namespace Utils
{

	class Application {
	public:

		explicit Application(uint32_t width, uint32_t height, const std::string & title);
		
		void Launch();

		void PushState(std::unique_ptr<GameStates::GameStateBase> state);
		void PopState();

		sf::RenderWindow & GetWindow();

	private:

		sf::RenderWindow window;
		std::stack<std::unique_ptr<GameStates::GameStateBase>> gameStates;

	};

}