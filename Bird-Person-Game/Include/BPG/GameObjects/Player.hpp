#pragma once

#include <memory>
#include <unordered_map>

#include <BPG/Utils/Animation.hpp>
#include <BPG/Extensions/Vector2.hpp>
#include <BPG/GameObjects/GameObject.hpp>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Time.hpp>

namespace GameObjects
{

	class Player : public GameObject {
		
		inline static constexpr float WALKING_SPEED = 500.f;
		inline static constexpr float SPRINTING_SPEED = WALKING_SPEED * 1.5f;

	private:

		enum class Direction {
			WalkingLeft,
			WalkingRight,
			WalkingUp,
			WalkingDown,

			StandingLeft,
			StandingRight,
			StandingUp,
			StandingDown
		};

	public:

		Player();

		void update(const sf::Time & deltaTime);

	protected:

		virtual const sf::Drawable & getDrawable() const override;

	private:

		Utils::Animation & getAnimation();

		void handleInput();
		void initializeAnimations();

	private:

		std::shared_ptr<sf::Texture> texture;
		sf::Sprite sprite;
		Extensions::Vector2f velocity;

		Direction direction;
		std::unordered_map<Direction, Utils::Animation> animations;


	};

}