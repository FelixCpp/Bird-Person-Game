#pragma once

#include <memory>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Time.hpp>

namespace GameObjects
{

	class Player : public sf::Drawable, public sf::Transformable {
		
		inline static constexpr float SPEED = 500.f;

	public:

		Player();

		void Update(const sf::Time & deltaTime);
		
	protected:

		virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

	private:

		void HandleInput();

	private:

		std::shared_ptr<sf::Texture> texture;
		sf::Sprite sprite;
		sf::Vector2f velocity;

	};

}