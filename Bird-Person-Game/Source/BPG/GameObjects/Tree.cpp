#include <BPG/GameObjects/Tree.hpp>
#include <BPG/Utils/Loaders/ResourceLoader.hpp>
#include <BPG/Extensions/Vector2.hpp>

namespace GameObjects
{

	Tree::Tree(const sf::Vector2f& position) :
		texture(nullptr),
		sprite()
	{
		if (this->texture = Utils::Loaders::TextureLoader::get("Assets/Textures/Tree.png")) {
			this->sprite.setTexture(*this->texture);
		}

		this->setPosition(position);
		this->setScale(5.f, 5.f);
	}

	sf::Vector2f Tree::getSize() const
	{
		if (this->texture)
		{
			return (sf::Vector2f)this->texture->getSize() * this->getScale();
		}

		return sf::Vector2f();
	}

	sf::FloatRect Tree::getBoundary() const
	{
		const sf::Vector2f pos = this->getPosition();
		const sf::Vector2f size = this->texture ? (sf::Vector2f)this->texture->getSize() : sf::Vector2f(0.f, 0.f);
		const sf::Vector2f scale = this->getScale();

		const float x = pos.x;
		const float y = pos.y;
		const float width  = size.x * scale.x;
		const float height = size.y * scale.y;

		return sf::FloatRect(x, y + height * 0.65f, width, height * 0.35f);
	}

	const sf::Drawable & Tree::getDrawable() const
	{
		return this->sprite;
	}

}