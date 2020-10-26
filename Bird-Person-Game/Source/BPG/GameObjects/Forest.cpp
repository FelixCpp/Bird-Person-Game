#include <BPG/GameObjects/Forest.hpp>
#include <BPG/Maths/Random.hpp>

#include <SFML/Graphics/RenderTarget.hpp>

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

}