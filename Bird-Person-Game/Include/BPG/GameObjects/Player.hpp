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
	public:

		Player();

		void update(const sf::Time & deltaTime);
		
	protected:

		virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

	private:

		std::shared_ptr<sf::Texture> texture;
		sf::Sprite sprite;

	};

}