#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>

namespace GameObjects
{

	class GameObject : public sf::Drawable, public sf::Transformable {
	protected:

		explicit GameObject(sf::Drawable& drawable);
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	private:

		sf::Drawable& drawable;

	};

}