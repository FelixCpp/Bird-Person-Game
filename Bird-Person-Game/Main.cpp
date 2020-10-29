#include <BPG/Utils/Application.hpp>

int main()
{
	Utils::Application(1024, 1024, "Bird-Person-Game")
		.launch();
}

//#include <BPG/Input/InputManager.hpp>
//#include <SFML/Graphics.hpp>
//#include <iostream>
//
//int main2()
//{
//	sf::RenderWindow window(sf::VideoMode(480, 480), "SFML");
//	window.setFramerateLimit(10);
//	window.setKeyRepeatEnabled(false);
//
//	Input::InputManager input;
//	
//	input.bind(sf::Keyboard::Escape)
//		.onKeyReleased([&window]() { window.close(); });
//
//	input.bind(sf::Keyboard::W)
//		.onKeyPressed([]() { std::cout << "Up Start 1" << std::endl; })
//		.onKeyDown([]() { std::cout << "Down 1" << std::endl; })
//		.onKeyReleased([]() { std::cout << "Up End 1" << std::endl; });
//
//	input.bind(sf::Keyboard::W)
//		.onKeyPressed([]() { std::cout << "Up Start 2" << std::endl; })
//		.onKeyDown([]() { std::cout << "Down 2" << std::endl; })
//		.onKeyReleased([]() { std::cout << "Up End 2" << std::endl; });
//
//	sf::Event event;
//	while (window.isOpen())
//	{
//		while (window.pollEvent(event))
//		{
//			input.onEvent(event);
//		}
//
//		input.listen();
//
//		window.clear();
//		window.display();
//	}
//
//	return EXIT_SUCCESS;
//}