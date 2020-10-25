#include <BPG/Utils/Application.hpp>

int main()
{
	Utils::Application(1024, 1024, "Bird-Person-Game")
		.Launch();
}