#include <BPG/GameObjects/FrameRateCounter.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <BPG/Utils/Loaders/ResourceLoader.hpp>

namespace GameObjects
{

	FrameRateCounter::FrameRateCounter() :
		font(nullptr),
		refreshRate(sf::milliseconds(250)),
		delayClock(),
		fpsClock(),
		frameCount(0u),
		fps(0.f)
	{
		if (this->font = Utils::Loaders::FontLoader::get("Assets/Fonts/Sansation/Sansation-Regular.ttf"))
		{
			this->setFont(*this->font);
			this->setCharacterSize(32);
		}
	}

	void FrameRateCounter::count()
	{
		this->frameCount++;

		if (this->delayClock.getElapsedTime() >= this->refreshRate)
		{
			this->fps = (float)this->frameCount / this->fpsClock.restart().asSeconds();
			this->setString("Fps: " + std::to_string((int)this->fps));
			this->frameCount = 0;
			this->delayClock.restart();
		}
	}

	void FrameRateCounter::setRefreshRate(const sf::Time & refreshRate)
	{
		this->refreshRate = refreshRate;
	}

	const sf::Time & FrameRateCounter::getRefreshRate() const
	{
		return this->refreshRate;
	}

	float FrameRateCounter::getFps() const
	{
		return this->fps;
	}

}