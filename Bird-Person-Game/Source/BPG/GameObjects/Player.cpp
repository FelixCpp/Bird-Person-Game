#include <BPG/GameObjects/Player.hpp>

#include <BPG/Maths/CollisionHandler.hpp>

#include <BPG/Utils/Loaders/ResourceLoader.hpp>

#include <SFML/Window/Keyboard.hpp>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include <iostream>

namespace GameObjects
{

	Player::Player() :
		texture(nullptr),
		velocity(0.f, 0.f),
		direction(Direction::WalkingRight),
		animations()
	{
		if (this->texture = Utils::Loaders::TextureLoader::get("Assets/Textures/Fox.png"))
		{
			this->setTexture(*this->texture);
		}

		this->setScale(2.f, 2.f);
		this->initializeAnimations();
	}

	void Player::update(const sf::Time & deltaTime)
	{
		this->handleInput();
		this->getAnimation().update(deltaTime);
		this->getAnimation().applyToSprite(*this);

		const sf::IntRect rect = this->getTextureRect();
		const sf::Vector2f size(rect.width / 2.f, rect.height / 2.f);
		this->setOrigin(size);

		const Maths::FVector2 change = this->velocity * deltaTime.asSeconds();
		this->move(change.toSFVector2());
		this->velocity *= 0.f;
	}

	sf::FloatRect Player::getBoundary() const
	{
		const sf::FloatRect boundary = this->getGlobalBounds();

		const float x = boundary.left;
		const float y = boundary.top;
		const float width = boundary.width;
		const float height = boundary.height;

		return sf::FloatRect(x + width * 0.225f, y + height * 0.15f, width * 0.55f, height * 0.8f);
	}

	void Player::onCollision(const BoundaryComponent & boundary)
	{
		const Maths::FVector2 toMove = Maths::CollisionHandler::getOverlap(*this, boundary);
		this->move(toMove.toSFVector2());
	}

	void Player::onCollisionFreed()
	{

	}

	Utils::Animation & Player::getAnimation()
	{
		return this->animations.at(this->direction);
	}

	void Player::handleInput()
	{
		// const Maths::FVector2 velocity = Utils::InputHandler::getPlayerVelocity(*this);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			this->velocity.y = -1.f;
			this->direction = Direction::WalkingUp;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			this->velocity.y = 1.f;
			this->direction = Direction::WalkingDown;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			this->velocity.x = -1.f;
			this->direction = Direction::WalkingLeft;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			this->velocity.x = 1.f;
			this->direction = Direction::WalkingRight;
		}

		const bool standing = this->velocity.x == 0.f && this->velocity.y == 0.f;
		if (standing)
		{
			if (this->direction == Direction::WalkingUp)    this->direction = Direction::StandingUp;
			if (this->direction == Direction::WalkingDown)  this->direction = Direction::StandingDown;
			if (this->direction == Direction::WalkingLeft)  this->direction = Direction::StandingLeft;
			if (this->direction == Direction::WalkingRight) this->direction = Direction::StandingRight;
		} else
		{
			float speed = 0.f;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift))
			{
				speed = SPRINTING_SPEED;
				this->getAnimation().setHoldTime(sf::milliseconds(50));
			} else
			{
				speed = WALKING_SPEED;
				this->getAnimation().setHoldTime(sf::milliseconds(100));
			}

			this->velocity.setLength(speed);
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