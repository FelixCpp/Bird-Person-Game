#pragma once

#include <functional>
#include <list>

namespace Input
{

	class KeyBinding {
	public:

		typedef std::function<void()> Action;
	
	public:

		KeyBinding();

		KeyBinding & onKeyPressed(const Action & action);
		KeyBinding & onKeyReleased(const Action & action);
		KeyBinding & onKeyDown(const Action & action);
		
		void invokeKeyPressed() const;
		void invokeKeyReleased() const;
		void invokeKeyDown() const;

	private:

		std::list<Action> onKeyPressedActions;
		std::list<Action> onKeyReleasedActions;
		std::list<Action> onKeyDownActions;

	};

}