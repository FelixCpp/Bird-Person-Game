#pragma once

#include <memory>
#include <unordered_map>

#include <SFML/Graphics/Texture.hpp>

#include <BPG/Utils/StaticObject.hpp>

namespace Utils
{

	class MemoryImageCache : public StaticObject {
	public:

		static std::shared_ptr<sf::Texture> Get(const std::string & filepath);

		static void Clear();

	private:

		static std::unordered_map<std::string, std::shared_ptr<sf::Texture>> textures;

	};
	
}