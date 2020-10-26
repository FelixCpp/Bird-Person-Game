#pragma once

#include <BPG/Utils/Caches/MemoryCache.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Image.hpp>

namespace Utils
{

	namespace Loaders
	{

		template<class TResourceType>
		class ResourceLoader {
		public:

			inline static std::shared_ptr<TResourceType> get(const std::string & filepath)
			{
				const auto data = cache.get(filepath);
				if (data == nullptr)
				{
					// Die data ist noch nicht im cache
					auto newItem = std::make_shared<TResourceType>();

					// Lade die datei
					if (newItem->loadFromFile(filepath))
					{
						cache.set(filepath, newItem);
						return newItem;
					}
				}

				return data;
			}

		private:

			inline static Caches::MemoryCache<TResourceType> cache;

		};

		typedef ResourceLoader<sf::Texture> TextureLoader;
		typedef ResourceLoader<sf::Font> FontLoader;
		typedef ResourceLoader<sf::Image> ImageLoader;

	}

}