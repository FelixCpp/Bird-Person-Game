#pragma once

#include <memory>

#include <BPG/GameStates/GameStateBase.hpp>
#include <BPG/GameObjects/Player.hpp>
#include <BPG/GameObjects/FrameRateCounter.hpp>
#include <BPG/GameObjects/Camera.hpp>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

namespace GameStates
{

	class PlayingGameState : public GameStateBase {
	public:
		
		explicit PlayingGameState(Utils::Application & application);
		virtual ~PlayingGameState() override = default;

		virtual void handleInput(const sf::Event & event) override;
		virtual void update(const sf::Time & deltaTime) override;
		virtual void draw() const override;

	private:

		std::shared_ptr<sf::Texture> backgroundTexture;
		sf::Sprite backgroundSprite;
		
		GameObjects::Camera camera;
		GameObjects::Player player;
		GameObjects::FrameRateCounter frameRateCounter;

		bool followPlayer;

	};


}