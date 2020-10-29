#include <BPG/Input/KeyBinding.hpp>

namespace Input
{

	KeyBinding::KeyBinding() :
		onKeyPressedActions(),
		onKeyReleasedActions()
	{
	}

	KeyBinding & KeyBinding::onKeyPressed(const Action & action)
	{
		this->onKeyPressedActions.push_back(action);
		return *this;
	}

	KeyBinding & KeyBinding::onKeyReleased(const Action & action)
	{
		this->onKeyReleasedActions.push_back(action);
		return *this;
	}

	KeyBinding & KeyBinding::onKeyDown(const Action & action)
	{
		this->onKeyDownActions.push_back(action);
		return *this;
	}

	void KeyBinding::invokeKeyPressed() const
	{
		for (const auto & action : this->onKeyPressedActions)
			action();
	}

	void KeyBinding::invokeKeyReleased() const
	{
		for (const auto & action : this->onKeyReleasedActions)
			action();
	}

	void KeyBinding::invokeKeyDown() const
	{
		for (const auto & action : this->onKeyDownActions)
			action();
	}

}