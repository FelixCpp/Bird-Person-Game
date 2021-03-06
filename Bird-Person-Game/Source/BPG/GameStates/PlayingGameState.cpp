#include <BPG/GameStates/PlayingGameState.hpp>

#include <BPG/Utils/Loaders/ResourceLoader.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <BPG/Utils/Application.hpp>

namespace GameStates
{

	PlayingGameState::PlayingGameState(Utils::Application & application) :
		GameStateBase(application),
		background("Assets/Textures/GrassBackground.jpg", 2, 2),
		counter(),
		forest(),
		player(),
		camera(this->window),
		followPlayer(true)
	{
		this->bindInput();
		
		this->camera.bindInput(this->input);
		this->player.bindInput(this->input);
		this->player.setPosition((this->background.getSize() / 2.f).toSFVector2());

		this->counter.setPosition(30.f, 30.f);
		this->forest.loadFromFile("Assets/WorldData/TreePositions.txt");
	}
		
	void PlayingGameState::update(const sf::Time & deltaTime)
	{
		this->counter.count();

		this->input.listen();
		this->player.update(deltaTime);

		this->forest.handleCollision(this->player);
		
		if (this->followPlayer) this->camera.setCenter(this->player.getPosition());
		else this->camera.update(deltaTime);
	}
	
	void PlayingGameState::draw() const
	{
		this->window.clear();

		this->window.setView(this->camera);
		// ----------------------------------------------
		// Alles was sich mit der Kamera bewegen soll:
		this->window.draw(this->background);
		this->window.draw(this->player);
		this->window.draw(this->forest);
		// ----------------------------------------------
		this->window.setView(this->window.getDefaultView());

		this->window.draw(this->counter);
	}

	void PlayingGameState::bindInput()
	{
		this->input.bind(sf::Keyboard::RControl).onReleased([this]() { this->followPlayer = !this->followPlayer; });
		
		this->input.bind(sf::Mouse::Wheel::VerticalWheel)
			.onChange([this](float delta) {
			if (delta > 0.f)
			{
				this->camera.zoom(0.9f);
			} else
			{
				this->camera.zoom(1.1f);
			}
		});
	}

}