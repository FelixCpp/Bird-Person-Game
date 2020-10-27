#include <BPG/GameObjects/Tree.hpp>
#include <BPG/Utils/Loaders/ResourceLoader.hpp>
#include <BPG/Extensions/Vector2.hpp>

namespace GameObjects
{

	Tree::Tree(const sf::Vector2f& position) :
		texture(nullptr)
	{
		if (this->texture = Utils::Loaders::TextureLoader::get("Assets/Textures/Tree.png")) {
			this->setTexture(*this->texture);
			this->setOrigin((sf::Vector2f)this->texture->getSize() / 2.f);
		}

		this->setPosition(position);
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