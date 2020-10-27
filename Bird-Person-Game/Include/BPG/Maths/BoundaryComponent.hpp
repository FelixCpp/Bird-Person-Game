#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Rect.hpp>

namespace Maths
{

	class BoundaryComponent {
	public:

		void drawBoundary(sf::RenderTarget & target) const;

		virtual sf::FloatRect getBoundary() const = 0;
		virtual void onCollision(const BoundaryComponent & boundary) = 0;
		virtual void onCollisionFreed() = 0;

	protected:

		BoundaryComponent();

	private:

		mutable sf::RectangleShape visual;

	};

}