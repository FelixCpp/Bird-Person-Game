#include <BPG/GameStates/PlayingGameState.hpp>

#include <BPG/Utils/MemoryImageCache.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace GameStates
{

	PlayingGameState::PlayingGameState(Utils::Application & application) :
		GameStateBase(application),
		backgroundTexture(nullptr),
		backgroundSprite(),
		player()
	{
		this->backgroundTexture = Utils::MemoryImageCache::Get("Assets/Textures/GrassBackground.jpg");

		if (auto texture = this->backgroundTexture)
		{
			this->window.setSize(texture->getSize());
			this->backgroundSprite.setTexture(*texture);
		}

		this->player.setPosition((sf::Vector2f)this->window.getSize() / 2.f);
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
		this->player.update(deltaTime);
	}
	
	void PlayingGameState::Draw() const
	{
		this->window.clear(sf::Color::Black);
		this->window.draw(this->backgroundSprite);
		this->window.draw(this->player);
	}

}