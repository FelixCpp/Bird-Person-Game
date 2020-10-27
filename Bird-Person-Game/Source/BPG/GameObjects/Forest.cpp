#include <BPG/GameObjects/Forest.hpp>
#include <BPG/Maths/Random.hpp>

#include <SFML/Graphics/RenderTarget.hpp>
#include <BPG/GameObjects/Player.hpp>

#include <fstream>
#include <iostream>

namespace GameObjects
{

	Forest::Forest() :
		trees(),
		boundary()
	{
	}

	bool Forest::loadFromFile(const std::string & filepath)
	{
		std::ifstream reader(filepath);
		if (!reader.is_open())
		{
			std::cerr << "Failed to open " << filepath << std::endl;
			return false;
		}

		this->trees.clear();

		while (reader.good())
		{
			float x = 0.f, y = 0.f;
			reader >> x >> y;
			
			this->trees.push_back(Tree(sf::Vector2f(x, y)));
		}

		reader.close();

		return true;
	}

	void Forest::handleCollision(Maths::BoundaryComponent & boundary)
	{
		for (const Tree & tree : this->trees)
		{
			if (tree.getBoundary().intersects(boundary.getBoundary()))
			{
				boundary.onCollision(tree);
				break;
			} else
			{
				boundary.onCollisionFreed();
			}
		}
	}

	void Forest::draw(sf::RenderTarget & target, sf::RenderStates states) const
	{
		for (const Tree & tree : this->trees)
		{
			target.draw(tree, states);
			//tree.drawBoundary(target);
		}
	}

}