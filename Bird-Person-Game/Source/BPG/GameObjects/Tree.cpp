#include <BPG/GameObjects/Tree.hpp>
#include <BPG/Utils/Loaders/ResourceLoader.hpp>

namespace GameObjects
{

	Tree::Tree(const sf::Vector2f& position) : 
		GameObject(this->sprite),
		texture(nullptr),
		sprite()
	{
		this->setPosition(position);
		this->setScale(5.f, 5.f);
		if (this->texture = Utils::Loaders::TextureLoader::get("Assets/Textures/Tree.png")) {
			this->sprite.setTexture(*this->texture);
		}

	}

}