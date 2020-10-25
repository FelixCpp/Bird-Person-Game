#include <BPG/GameObjects/Player.hpp>
#include <BPG/Utils/MemoryCache.hpp>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Keyboard.hpp>

#include <iostream>

namespace GameObjects
{

	Player::Player() :
		texture(Utils::TextureMemoryCache::get("Assets/Textures/Fox.png")),
		sprite(),
		velocity(0.f, 0.f),
		direction(Direction::WalkingRight),
		animations()
	{
		if (this->texture)
		{
			this->sprite.setTexture(*this->texture);
			this->sprite.setScale(2.f, 2.f);
		}

		this->initializeAnimations();
	}

	void Player::update(const sf::Time & deltaTime)
	{
		this->handleInput();
		this->getAnimation().update(deltaTime);
		this->getAnimation().applyToSprite(this->sprite);

		const sf::IntRect rect = this->sprite.getTextureRect();
		const sf::Vector2f size(rect.width / 2.f, rect.height / 2.f);
		this->sprite.setOrigin(size);

		this->move(this->velocity * deltaTime.asSeconds());
		this->velocity.x = this->velocity.y = 0.f;
	}

	void Player::draw(sf::RenderTarget & target, sf::RenderStates states) const
	{
		states.transform *= this->getTransform();
		target.draw(this->sprite, states);
	}

	Utils::Animation & Player::getAnimation()
	{
		return this->animations.at(this->direction);
	}

	void Player::handleInput()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			this->velocity.y = -SPEED;
			this->direction = Direction::WalkingUp;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			this->velocity.y = SPEED;
			this->direction = Direction::WalkingDown;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			this->velocity.x = -SPEED;
			this->direction = Direction::WalkingLeft;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			this->velocity.x = SPEED;
			this->direction = Direction::WalkingRight;
		}

		if (this->velocity.x == 0.f && this->velocity.y == 0.f)
		{
			if (this->direction == Direction::WalkingUp)    this->direction = Direction::StandingUp;
			if (this->direction == Direction::WalkingDown)  this->direction = Direction::StandingDown;
			if (this->direction == Direction::WalkingLeft)  this->direction = Direction::StandingLeft;
			if (this->direction == Direction::WalkingRight) this->direction = Direction::StandingRight;
		}
	}

	void Player::initializeAnimations()
	{
		if (auto texture = this->texture)
		{
			this->animations.insert({ Direction::WalkingDown,  Utils::Animation(*texture, 3, 4, 0, 3, 0, 1) });
			this->animations.insert({ Direction::WalkingLeft,  Utils::Animation(*texture, 3, 4, 0, 3, 1, 1) });
			this->animations.insert({ Direction::WalkingRight, Utils::Animation(*texture, 3, 4, 0, 3, 2, 1) });
			this->animations.insert({ Direction::WalkingUp,    Utils::Animation(*texture, 3, 4, 0, 3, 3, 1) });

			this->animations.insert({ Direction::StandingDown,  Utils::Animation(*texture, 3, 4, 1, 1, 0, 1) });
			this->animations.insert({ Direction::StandingLeft,  Utils::Animation(*texture, 3, 4, 1, 1, 1, 1) });
			this->animations.insert({ Direction::StandingRight, Utils::Animation(*texture, 3, 4, 1, 1, 2, 1) });
			this->animations.insert({ Direction::StandingUp,    Utils::Animation(*texture, 3, 4, 1, 1, 3, 1) });
		}
	}

}