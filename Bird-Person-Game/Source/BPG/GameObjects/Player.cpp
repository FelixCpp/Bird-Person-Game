#include <BPG/GameObjects/Player.hpp>
#include <BPG/Utils/MemoryCache.hpp>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Keyboard.hpp>

namespace GameObjects
{

	Player::Player() :
		texture(Utils::TextureMemoryCache::Get("Assets/Textures/Fox.png")),
		sprite(),
		velocity(0.f, 0.f),
		direction(Direction::Right),
		animations()
	{
		if (this->texture)
		{
			this->sprite.setTexture(*this->texture);
		}

		this->InitializeAnimations();
	}

	void Player::Update(const sf::Time & deltaTime)
	{
		this->HandleInput();
		this->GetAnimation().Update(deltaTime);
		this->GetAnimation().ApplyToSprite(this->sprite),
		
		this->move(this->velocity * deltaTime.asSeconds());
		this->velocity.x = this->velocity.y = 0.f;
	}

	void Player::draw(sf::RenderTarget & target, sf::RenderStates states) const
	{
		states.transform *= this->getTransform();
		target.draw(this->sprite, states);
	}

	Utils::Animation & Player::GetAnimation()
	{
		return this->animations.at(this->direction);
	}

	void Player::HandleInput()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			this->velocity.y = -SPEED;
			this->direction = Direction::Up;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			this->velocity.y = SPEED;
			this->direction = Direction::Down;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			this->velocity.x = -SPEED;
			this->direction = Direction::Left;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			this->velocity.x = SPEED;
			this->direction = Direction::Right;
		}
	}

	void Player::InitializeAnimations()
	{
		if (auto texture = this->texture)
		{
			this->animations.insert({ Direction::Down,  Utils::Animation(*texture, 3, 4, 0, 3, 0, 1) });
			this->animations.insert({ Direction::Left,  Utils::Animation(*texture, 3, 4, 0, 3, 1, 1) });
			this->animations.insert({ Direction::Right, Utils::Animation(*texture, 3, 4, 0, 3, 2, 1) });
			this->animations.insert({ Direction::Up,    Utils::Animation(*texture, 3, 4, 0, 3, 3, 1) });
		}
	}

}