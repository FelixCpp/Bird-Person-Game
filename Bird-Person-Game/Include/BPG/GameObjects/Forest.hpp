#pragma once

#include <vector>

#include <BPG/GameObjects/Tree.hpp>
#include <BPG/Maths/BoundaryComponent.hpp>

#include <SFML/Graphics/Drawable.hpp>

namespace GameObjects
{

	class Forest : public sf::Drawable {
	public:

		Forest();

		bool loadFromFile(const std::string & filepath);

		void handleCollision(Maths::BoundaryComponent & boundary);

	protected:

		virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

	private:

		std::vector<Tree> trees;

	};

}