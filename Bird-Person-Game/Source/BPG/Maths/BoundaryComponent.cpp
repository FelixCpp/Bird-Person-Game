#include <BPG/Maths/BoundaryComponent.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

namespace Maths
{

	BoundaryComponent::BoundaryComponent() :
		visual()
	{
		this->visual.setFillColor(sf::Color::Transparent);
		this->visual.setOutlineThickness(3.f);
	}

	void BoundaryComponent::drawBoundary(sf::RenderTarget & target) const
	{
		const sf::FloatRect boundary = this->getBoundary();
		this->visual.setPosition(boundary.left, boundary.top);
		this->visual.setSize(sf::Vector2f(boundary.width, boundary.height));

		target.draw(this->visual);
	}

}