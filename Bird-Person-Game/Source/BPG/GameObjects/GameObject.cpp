#include <BPG/GameObjects/GameObject.hpp>

#include <SFML/Graphics/RenderTarget.hpp>

namespace GameObjects
{

	void GameObject::draw(sf::RenderTarget & target, sf::RenderStates states) const
	{
		states.transform *= this->getTransform();
		target.draw(this->getDrawable(), states);	
	}

}