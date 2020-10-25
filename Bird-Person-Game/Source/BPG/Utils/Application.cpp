#include <BPG/Utils/Application.hpp>
#include <SFML/Window/Event.hpp>

#include <BPG/GameStates/PlayingGameState.hpp>

namespace Utils
{

	Application::Application(uint32_t width, uint32_t height, const std::string & title) :
		window(sf::VideoMode(width, height), title, sf::Style::Close), // Fenster erstellen
		gameStates() // leerer stack
	{
		this->window.setFramerateLimit(60u);
	}
	
	void Application::Launch()
	{
		this->PushState(std::make_unique<GameStates::PlayingGameState>(*this));

		sf::Clock clock;
		sf::Event event;
		while (this->window.isOpen() && !this->gameStates.empty())
		{
			auto & state = this->gameStates.top();

			// Dispatch die window events
			while (this->window.pollEvent(event))
			{
				if (event.type == sf::Event::EventType::Closed)
				{
					this->window.close();
				} else if (event.type == sf::Event::EventType::Resized)
				{
					sf::FloatRect visibleArea(0, 0, (float)event.size.width, (float)event.size.height);
					window.setView(sf::View(visibleArea));
				} else
				{
					state->HandleInput(event);
				}
			}

			// Update & Draw mit der vergangenden Zeit seit dem letzen durchlauf
			const sf::Time deltaTime = clock.restart();
			state->Update(deltaTime);
			state->Draw();

			// catch window events
			this->window.display();
		}
	}
	
	void Application::PushState(std::unique_ptr<GameStates::GameStateBase> state)
	{
		this->gameStates.push(std::move(state));
	}
	
	void Application::PopState()
	{
		// Wir wollen die gamestates nicht leeren können
		if (this->gameStates.size() > 1)
		{
			this->gameStates.pop();
		}
	}

	sf::RenderWindow & Application::GetWindow()
	{
		return this->window;
	}

}