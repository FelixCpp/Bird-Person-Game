#include <BPG/Utils/MemoryImageCache.hpp>

#include <iostream>

namespace Utils
{

	std::unordered_map<std::string, std::shared_ptr<sf::Texture>> MemoryImageCache::textures;

	std::shared_ptr<sf::Texture> MemoryImageCache::Get(const std::string & filepath)
	{
		const auto itr = textures.find(filepath);

		// Falls der iterator in dem dictionary den filepath findet:
		if (itr != textures.end())
		{
			return itr->second; //< gib die texture zurück
		} else
		{
			// erstelle eine Texture
			auto texture = std::make_shared<sf::Texture>();

			// Lade die texture von einer Datei
			if (texture->loadFromFile(filepath))
			{
				// Füge die texture unter dem key (filepath) hinzu
				textures.insert(std::make_pair(filepath, texture));

				// gib die geladene texture zurück
				return texture;
			}
		}

		// Fehler: die datei wurde nicht erfolgreich geladen
		return nullptr;
	}

	void MemoryImageCache::Clear()
	{
		// leere den cache/das dictionary
		textures.clear();
	}

}