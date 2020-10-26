#include <BPG/Extensions/RenderWindow.hpp>

#include <Windows.h>

namespace Extensions
{

	RenderWindow::RenderWindow(const sf::VideoMode & mode, const std::string & title, uint32_t style, const sf::ContextSettings & settings) :
		sf::RenderWindow(mode, title, style, settings)
	{
        sf::WindowHandle handle = this->getSystemHandle();
        HCURSOR cursor = LoadCursorFromFileA("Assets/Cursors/aerowedge.cur"); //.cur or .ani
        SetCursor(cursor);
        SetClassLongPtr(handle, GCLP_HCURSOR, reinterpret_cast<LONG_PTR>(cursor));
	}

}