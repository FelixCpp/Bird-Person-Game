#pragma once

#include <stack>
#include <memory>
#include <string>

#include <SFML/Graphics/RenderWindow.hpp>

#include <BPG/GameStates/GameStateBase.hpp>
#include <BPG/Extensions/RenderWindow.hpp>

namespace Utils
{

	class Application {
	public:

		explicit Application(uint32_t width, uint32_t height, const std::string & title);
		
		void launch();

		void pushState(std::unique_ptr<GameStates::GameStateBase> state);
		void popState();

		Extensions::RenderWindow & getWindow();

	private:

		Extensions::RenderWindow window;
		std::stack<std::unique_ptr<GameStates::GameStateBase>> gameStates;

	};

}