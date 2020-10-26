#pragma once

#include <memory>

#include <BPG/GameObjects/GameObject.hpp>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

namespace GameObjects
{

	class Tree : public GameObject {
	public:

		explicit Tree(const sf::Vector2f & position);
	
		sf::Vector2f getSize() const;
		sf::FloatRect getBoundary() const;

	protected:

		virtual const sf::Drawable & getDrawable() const override;

	private:

		std::shared_ptr<sf::Texture> texture;
		sf::Sprite sprite;

	};

}