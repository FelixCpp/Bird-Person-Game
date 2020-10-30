#include <BPG/GameStates/MapEditorGameState.hpp>

#include <SFML/Graphics/RenderWindow.hpp>

namespace GameStates
{
	MapEditorGameState::MapEditorGameState(Utils::Application& application) :
		GameStateBase(application),
		background("Assets/Textures/GrassBackground.jpg", 1, 1),
		camera(this->window)
	{
		this->background.setColor(sf::Color(255,255,255,128));
		this->camera.bindInput(this->input);
		this->input.bind(sf::Mouse::VerticalWheel).onChange([this](float delta)
		{
			if (delta > 0.f) {
				this->camera.zoom(0.9f);
			} else {
				this->camera.zoom(1.1f);
			}
		});
	}

	void MapEditorGameState::update(const sf::Time & deltaTime)
	{
		const sf::Vector2f mousePos = this->window.mapPixelToCoords(sf::Mouse::getPosition(this->window));
		const sf::Vector2f offset = this->background.getSize().toSFVector2() / 2.f;

		this->background.setPosition(mousePos - offset);
		this->input.listen();
		this->camera.update(deltaTime);

	}

	void MapEditorGameState::draw() const
	{

		this->window.clear();
		this->window.setView(this->camera);
		this->window.draw(this->background);

	}
	
}

