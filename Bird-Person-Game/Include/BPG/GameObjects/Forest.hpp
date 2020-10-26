#pragma once

#include <vector>

#include <BPG/GameObjects/Tree.hpp>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

namespace GameObjects
{

	class Forest : public sf::Drawable {
	public:

		explicit Forest(size_t treeCount, const sf::FloatRect & area);

	protected:

		virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

	private:

		void generateForest(size_t treeCount);

	private:

		sf::FloatRect area;
		std::vector<Tree> trees;

		mutable sf::RectangleShape boundary;

	};

}