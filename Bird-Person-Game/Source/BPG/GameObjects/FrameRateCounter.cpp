#include <BPG/GameObjects/FrameRateCounter.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <BPG/Utils/MemoryCache.hpp>

namespace GameObjects
{

	FrameRateCounter::FrameRateCounter() :
		text(),
		font(nullptr),
		refreshRate(sf::milliseconds(250)),
		delayClock(),
		fpsClock(),
		frameCount(0u),
		fps(0.f)
	{
		if (this->font = Utils::FontMemoryCache::Get("Assets/Fonts/Sansation/Sansation-Regular.ttf"))
		{
			this->text.setFont(*this->font);
			this->text.setCharacterSize(32);
		}
	}

	void FrameRateCounter::Count()
	{
		this->frameCount++;

		if (this->delayClock.getElapsedTime() >= this->refreshRate)
		{
			this->fps = (float)this->frameCount / this->fpsClock.restart().asSeconds();
			this->text.setString("Fps: " + std::to_string((int)this->fps));
			this->frameCount = 0;
			this->delayClock.restart();
		}
	}

	void FrameRateCounter::SetRefreshRate(const sf::Time & refreshRate)
	{
		this->refreshRate = refreshRate;
	}

	const sf::Time & FrameRateCounter::GetRefreshRate() const
	{
		return this->refreshRate;
	}

	float FrameRateCounter::GetFps() const
	{
		return this->fps;
	}

	void FrameRateCounter::draw(sf::RenderTarget & target, sf::RenderStates states) const
	{
		states.transform *= this->getTransform();
		target.draw(this->text, states);
	}

}