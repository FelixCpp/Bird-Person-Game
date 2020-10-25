#include <BPG/GameStates/PlayingGameState.hpp>

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace GameStates
{

	PlayingGameState::PlayingGameState(Utils::Application & application)
		: GameStateBase(application)
	{
	}
	
	void PlayingGameState::HandleInput(const sf::Event & event)
	{
		switch (event.type)
		{
			default:
				break;
		}
	}
	
	void PlayingGameState::Update(const sf::Time & deltaTime)
	{
		
	}
	
	void PlayingGameState::Draw() const
	{
		this->window.clear(sf::Color::Black);
	}

}