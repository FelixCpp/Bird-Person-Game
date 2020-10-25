#pragma once

#include <unordered_map>

#include <BPG/Utils/Caches/ResourceCache.hpp>

namespace Utils
{

	namespace Caches
	{

		template<class TResourceType>
		class MemoryCache : public ResourceCache<TResourceType> {
		public:

			virtual void set(const std::string & key, const std::shared_ptr<TResourceType> & data) override
			{
				this->cache[key] = data;
			}

			virtual std::shared_ptr<TResourceType> get(const std::string & key) const override
			{
				const auto itr = this->cache.find(key);
				if (itr != this->cache.end())
				{
					return itr->second;
				}

				return nullptr;
			}

		private:

			std::unordered_map<std::string, std::shared_ptr<TResourceType>> cache;

		};

	}

}