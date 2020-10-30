#include <BPG/Input/InputBinding.hpp>

namespace Input
{

	InputBinding & InputBinding::onPressed(const Action & action)
	{
		this->pressedActions.push_back(action);
		return *this;
	}

	InputBinding & InputBinding::onReleased(const Action & action)
	{
		this->releasedActions.push_back(action);
		return *this;
	}

	InputBinding & InputBinding::onDown(const Action & action)
	{
		this->downActions.push_back(action);
		return *this;
	}

	void InputBinding::invokePressed() const
	{
		for (const auto & action : this->pressedActions) action();
	}

	void InputBinding::invokeReleased() const
	{
		for (const auto & action : this->releasedActions) action();
	}

	void InputBinding::invokeDown() const
	{
		for (const auto & action : this->downActions) action();
	}

	MouseWheelBinding & MouseWheelBinding::onChange(const Action & action)
	{
		this->changeActions.push_back(action);
		return *this;
	}

	void MouseWheelBinding::invokeChange(float delta) const
	{
		for (const auto & action : this->changeActions) action(delta);
	}

}