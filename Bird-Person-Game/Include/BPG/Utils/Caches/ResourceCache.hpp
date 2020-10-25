#pragma once

#include <memory>
#include <string>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>

namespace Utils
{

	namespace Caches
	{

		template<class TResourceType>
		struct ResourceCache {

			using DataType = std::shared_ptr<TResourceType>;
			using KeyType = std::string;

			virtual void set(const KeyType & key, const DataType & texture) = 0;
			virtual DataType get(const KeyType & key) const = 0;

		};

		typedef ResourceCache<sf::Texture> TextureCache;
		typedef ResourceCache<sf::Font> FontCache;

	}

}