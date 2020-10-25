#include <BPG/GameObjects/Player.hpp>
#include <BPG/Utils/MemoryImageCache.hpp>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Keyboard.hpp>

namespace GameObjects
{

	Player::Player() :
		texture(Utils::MemoryImageCache::Get("Assets/Textures/Fox.png")),
		sprite(),
		velocity(0.f, 0.f)
	{
		if (this->texture != nullptr)
		{
			this->sprite.setTexture(*this->texture);
		}
	}

	void Player::Update(const sf::Time & deltaTime)
	{
		this->HandleInput();

		this->move(this->velocity * deltaTime.asSeconds());
		this->velocity.x = this->velocity.y = 0.f;
	}

	void Player::draw(sf::RenderTarget & target, sf::RenderStates states) const
	{
		states.transform = this->getTransform();
		target.draw(this->sprite, states);
	}

	void Player::HandleInput()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			this->velocity.y = -SPEED;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			this->velocity.y = SPEED;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			this->velocity.x = -SPEED;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			this->velocity.x = SPEED;
		}
	}

}