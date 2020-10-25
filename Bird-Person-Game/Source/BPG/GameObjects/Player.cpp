#include <BPG/GameObjects/Player.hpp>
#include <BPG/Utils/MemoryImageCache.hpp>

#include <SFML/Graphics/RenderTarget.hpp>

namespace GameObjects
{

	Player::Player() :
		texture(Utils::MemoryImageCache::Get("Assets/Textures/Fox.png")),
		sprite()
	{
		if (this->texture != nullptr)
		{
			this->sprite.setTexture(*this->texture);
		}
	}

	void Player::update(const sf::Time & deltaTime)
	{
	}

	void Player::draw(sf::RenderTarget & target, sf::RenderStates states) const
	{
		states.transform = this->getTransform();
		target.draw(this->sprite);
	}

}