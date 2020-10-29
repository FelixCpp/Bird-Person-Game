#include <BPG/GameStates/GameStateBase.hpp>

#include <BPG/Utils/Application.hpp>

namespace GameStates
{

	GameStateBase::GameStateBase(Utils::Application & application) :
		app(application),
		window(application.getWindow()),
		input()
	{
	}

	GameStateBase::~GameStateBase()
	{
		this->input.clear();
	}

	void GameStateBase::onEvent(const sf::Event & event)
	{
		this->input.onEvent(event);
	}

}