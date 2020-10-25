#pragma once

#include <memory>
#include <unordered_map>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>

#include <BPG/Utils/StaticObject.hpp>

namespace Utils
{

	template<class TCacheType, typename TKeyType, typename = std::enable_if_t<std::is_default_constructible_v<TCacheType>>>
	class MemoryCache : public StaticObject {
	public:

		using CacheType = std::shared_ptr<TCacheType>;
		using KeyType = TKeyType;

		inline static CacheType get(const KeyType & key)
		{
			const auto itr = cache.find(key);
			if (itr != cache.end())
			{
				return itr->second;
			} else
			{
				auto newItem = std::make_shared<TCacheType>();
				if (newItem->loadFromFile(key))
				{
					cache.insert(std::make_pair(key, newItem));
					return newItem;
				}
			}

			return nullptr;
		}

		inline static void clear()
		{
			cache.clear();
		}

	private:

		inline static std::unordered_map<KeyType, CacheType> cache;

	};

	typedef MemoryCache<sf::Texture, std::string> TextureMemoryCache;
	typedef MemoryCache<sf::Font, std::string> FontMemoryCache;

}