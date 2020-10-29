#pragma once

#include <memory>

#include <BPG/GameStates/GameStateBase.hpp>
#include <BPG/GameObjects/StaticImage.hpp>

#include <BPG/Extensions/View.hpp>
#include <BPG/GameObjects/FrameRateCounter.hpp>
#include <BPG/GameObjects/Forest.hpp>
#include <BPG/GameObjects/Player.hpp>

namespace GameStates
{

	class PlayingGameState : public GameStateBase {
	public:
		
		explicit PlayingGameState(Utils::Application & application);
		virtual ~PlayingGameState() override = default;

		virtual void update(const sf::Time & deltaTime) override;
		virtual void draw() const override;

	private:

		void bindInput();

	private:

		GameObjects::StaticImage background;
		GameObjects::FrameRateCounter counter;
		GameObjects::Forest forest;
		GameObjects::Player player;

		Extensions::Camera camera;
		
		bool followPlayer;

	};


}