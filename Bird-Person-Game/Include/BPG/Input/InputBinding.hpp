#pragma once

#include <functional>
#include <list>

namespace Input
{

	class InputBinding {

		typedef std::function<void()> Action;

	public:

		InputBinding & onPressed(const Action & action);
		InputBinding & onReleased(const Action & action);
		InputBinding & onDown(const Action & action);

		void invokePressed() const;
		void invokeReleased() const;
		void invokeDown() const;

	private:

		std::list<Action> pressedActions;
		std::list<Action> releasedActions;
		std::list<Action> downActions;

	};

	class MouseWheelBinding {
		
		typedef std::function<void(float delta)> Action;

	public:

		MouseWheelBinding & onChange(const Action & action);

		void invokeChange(float delta) const;

	private:

		std::list<Action> changeActions;
		
	};

}