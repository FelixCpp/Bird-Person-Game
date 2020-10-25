#pragma once

#include <memory>
#include <unordered_map>

#include <BPG/Utils/Animation.hpp>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Time.hpp>

namespace GameObjects
{

	class Player : public sf::Drawable, public sf::Transformable {
		
		inline static constexpr float SPEED = 500.f;

	private:

		enum class Direction {
			Left,
			Right,
			Up,
			Down
		};

	public:

		Player();

		void Update(const sf::Time & deltaTime);
		
	protected:

		virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

	private:

		Utils::Animation & GetAnimation();

		void HandleInput();
		void InitializeAnimations();

	private:

		std::shared_ptr<sf::Texture> texture;
		sf::Sprite sprite;
		sf::Vector2f velocity;

		Direction direction;
		std::unordered_map<Direction, Utils::Animation> animations;


	};

}