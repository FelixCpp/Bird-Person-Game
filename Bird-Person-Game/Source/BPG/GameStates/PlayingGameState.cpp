#include <BPG/GameStates/PlayingGameState.hpp>

#include <BPG/Utils/Loaders/ResourceLoader.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <BPG/Utils/Application.hpp>

namespace GameStates
{

	PlayingGameState::PlayingGameState(Utils::Application & application) :
		GameStateBase(application),
		backgroundTexture(nullptr),
		backgroundSprite(),
		camera(application.getWindow()),
		player(),
		frameRateCounter(),
		followPlayer(true)
	{
		this->backgroundTexture = Utils::Loaders::TextureLoader::get("Assets/Textures/GrassBackground.jpg");

		if (auto texture = this->backgroundTexture)
		{
			this->window.setSize(texture->getSize());
			texture->setRepeated(true);

			this->backgroundSprite.setTexture(*texture);
			this->backgroundSprite.setTextureRect(sf::IntRect(-3000, -3000, 6000, 6000));
		}

		this->player.setPosition((sf::Vector2f)this->window.getSize() / 2.f);
		this->frameRateCounter.setPosition(sf::Vector2f(30.f, 30.f));
	}
	
	void PlayingGameState::handleInput(const sf::Event & event)
	{
		switch (event.type)
		{
			case sf::Event::EventType::MouseWheelScrolled:
			{
				auto & args = event.mouseWheelScroll;
				if (args.wheel == sf::Mouse::Wheel::VerticalWheel)
				{
					bool forwards = args.delta > 0;

					if (forwards)
					{
						this->camera.zoom(0.9f);
					} else
					{
						this->camera.zoom(1.1f);
					}
				}
			} break;

			case sf::Event::KeyPressed:
			{
				auto & args = event.key;
				if (args.code == sf::Keyboard::Key::RControl)
				{
					this->followPlayer = !this->followPlayer;
				}
			} break;

			default:
				break;
		}
	}
	
	void PlayingGameState::update(const sf::Time & deltaTime)
	{
		this->player.update(deltaTime);
		this->frameRateCounter.count();

		if (this->followPlayer)
		{
			this->camera.setCenter(this->player.getPosition());
		} else
		{
			this->camera.handleInput(deltaTime);
		}
	}
	
	void PlayingGameState::draw() const
	{
		this->window.clear(sf::Color::Black);
		
		this->window.setView(this->camera);
		// ----------------------------------------------
		// Alles was mit der view bewegt werden soll ...
		this->window.draw(this->backgroundSprite);
		this->window.draw(this->player);
		// ----------------------------------------------
		this->window.setView(this->window.getDefaultView());

		this->window.draw(this->frameRateCounter);
	}

}