#include <BPG/GameStates/PlayingGameState.hpp>

#include <BPG/Utils/MemoryCache.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <BPG/Utils/Application.hpp>

namespace GameStates
{

	PlayingGameState::PlayingGameState(Utils::Application & application) :
		GameStateBase(application),
		backgroundTexture(nullptr),
		backgroundSprite(),
		view(sf::Vector2f(0.f, 0.f), sf::Vector2f(application.GetWindow().getSize())),
		player(),
		frameRateCounter()
	{
		this->backgroundTexture = Utils::TextureMemoryCache::Get("Assets/Textures/GrassBackground.jpg");

		if (auto texture = this->backgroundTexture)
		{
			this->window.setSize(texture->getSize());
			this->backgroundSprite.setTexture(*texture);
		}

		this->player.setPosition((sf::Vector2f)this->window.getSize() / 2.f);
		this->frameRateCounter.setPosition(sf::Vector2f(30.f, 30.f));
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
		this->player.Update(deltaTime);
		this->view.setCenter(this->player.getPosition());

		this->frameRateCounter.Count();
	}
	
	void PlayingGameState::Draw() const
	{
		this->window.clear(sf::Color::Black);
		this->window.setView(this->view);
		this->window.draw(this->backgroundSprite);
		this->window.draw(this->player);
		this->window.setView(this->window.getDefaultView());
		this->window.draw(this->frameRateCounter);
	}

}