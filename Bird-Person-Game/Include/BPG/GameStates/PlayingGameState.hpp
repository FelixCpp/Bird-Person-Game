#pragma once

#include <memory>

#include <BPG/GameStates/GameStateBase.hpp>
#include <BPG/GameObjects/Player.hpp>
#include <BPG/GameObjects/FrameRateCounter.hpp>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

namespace GameStates
{

	class PlayingGameState : public GameStateBase {
	public:
		
		explicit PlayingGameState(Utils::Application & application);
		virtual ~PlayingGameState() override = default;

		virtual void HandleInput(const sf::Event & event) override;
		virtual void Update(const sf::Time & deltaTime) override;
		virtual void Draw() const override;

	private:

		std::shared_ptr<sf::Texture> backgroundTexture;
		sf::Sprite backgroundSprite;

		GameObjects::Player player;
		GameObjects::FrameRateCounter frameRateCounter;

	};


}