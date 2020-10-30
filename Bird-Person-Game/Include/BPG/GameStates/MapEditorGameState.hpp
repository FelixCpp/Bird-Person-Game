#pragma once

#include <BPG/GameStates/GameStateBase.hpp>

#include <BPG/GameObjects/StaticImage.hpp>
#include <BPG/Extensions/View.hpp>

namespace GameStates
{

	class MapEditorGameState : public GameStateBase {
	public:

		explicit MapEditorGameState(Utils::Application & application);
		virtual ~MapEditorGameState() override = default;

		virtual void update(const sf::Time & deltaTime) override;
		virtual void draw() const override;

	private:

		GameObjects::StaticImage background;

		Extensions::Camera camera;

	};


}