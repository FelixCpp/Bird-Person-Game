#include <BPG/GameObjects/Tree.hpp>
#include <BPG/Utils/Loaders/ResourceLoader.hpp>

namespace GameObjects
{

	Tree::Tree(const Maths::FVector2 & position) :
		texture(nullptr)
	{
		if (this->texture = Utils::Loaders::TextureLoader::get("Assets/Textures/Tree.png")) {
			this->setTexture(*this->texture);
			this->setOrigin((sf::Vector2f)this->texture->getSize() / 2.f);
		}

		this->setPosition(position.toSFVector2());
		this->setScale(5.f, 5.f);
	}

	sf::FloatRect Tree::getBoundary() const
	{
		const sf::FloatRect boundary = this->getGlobalBounds();
		
		const float x = boundary.left;
		const float y = boundary.top;
		const float width  = boundary.width;
		const float height = boundary.height;
		
		return sf::FloatRect(x + width * 0.225f, y + height * 0.5f, width * 0.55f, height * 0.35f);
	}

}