#include <BPG/GameObjects/GameObject.hpp>

#include <SFML/Graphics/RenderTarget.hpp>

namespace GameObjects
{
	GameObject::GameObject(sf::Drawable& drawable) :
		drawable(drawable)
	{
	}
	void GameObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		states.transform *= this->getTransform();
		target.draw(this->drawable, states);
	}

}