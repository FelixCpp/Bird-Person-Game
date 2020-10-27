#pragma once

#include <memory>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <BPG/Maths/BoundaryComponent.hpp>
#include <BPG/Maths/Vector2.hpp>

namespace GameObjects
{

	class Tree : public sf::Sprite, public Maths::BoundaryComponent {
	public:

		explicit Tree(const Maths::FVector2 & position);

		virtual sf::FloatRect getBoundary() const override;
		virtual void onCollision(const BoundaryComponent & boundary) override {}
		virtual void onCollisionFreed() override {}

	private:

		std::shared_ptr<sf::Texture> texture;
		
	};

}