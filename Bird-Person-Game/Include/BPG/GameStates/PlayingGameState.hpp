#pragma once

#include <BPG/GameStates/GameStateBase.hpp>

namespace GameStates
{

	class PlayingGameState : public GameStateBase {
	public:
		
		explicit PlayingGameState(Utils::Application & application);
		virtual ~PlayingGameState() override = default;

		virtual void HandleInput(const sf::Event & event) override;
		virtual void Update(const sf::Time & deltaTime) override;
		virtual void Draw() const override;

	};


}