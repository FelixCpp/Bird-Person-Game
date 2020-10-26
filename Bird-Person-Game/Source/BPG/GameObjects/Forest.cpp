#include <BPG/GameObjects/Forest.hpp>
#include <BPG/Maths/Random.hpp>

#include <SFML/Graphics/RenderTarget.hpp>

namespace GameObjects
{

	Forest::Forest(size_t treeCount, const sf::FloatRect & area) :
		trees(),
		area(area),
		boundary()
	{
		this->generateForest(treeCount);
	}

	void Forest::draw(sf::RenderTarget & target, sf::RenderStates states) const
	{
		for (const Tree & tree : this->trees)
		{
			target.draw(tree, states);
			
			sf::FloatRect boundary = tree.getBoundary();
			this->boundary.setPosition(boundary.left, boundary.top);
			this->boundary.setSize(sf::Vector2f(boundary.width, boundary.height));
			this->boundary.setFillColor(sf::Color::Transparent);
			this->boundary.setOutlineThickness(3.f);
			target.draw(this->boundary);
		}
	}

	void Forest::generateForest(size_t treeCount)
	{
		this->trees.resize(treeCount, Tree(sf::Vector2f(0.f, 0.f)));

		const float left   = this->area.left;
		const float top    = this->area.top;
		const float right  = left + this->area.width;
		const float bottom = top  + this->area.height;

		for (Tree & tree : this->trees)
		{
			float x = Maths::Random::get(left, right);
			float y = Maths::Random::get(top, bottom);
			tree.setPosition(x, y);
		}
	}

}