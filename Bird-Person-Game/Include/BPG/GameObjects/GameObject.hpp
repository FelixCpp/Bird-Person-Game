#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>

namespace GameObjects
{

	class GameObject : public sf::Drawable, public sf::Transformable {
	public:

		virtual ~GameObject() = default;

	protected:

		GameObject() = default;

	protected:
		
		virtual const sf::Drawable & getDrawable() const = 0;
		virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

	};

}