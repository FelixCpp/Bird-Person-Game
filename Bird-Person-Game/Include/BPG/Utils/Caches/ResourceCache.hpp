#pragma once

#include <memory>
#include <string>

namespace Utils
{

	namespace Caches
	{

		template<class TResourceType>
		struct ResourceCache {

			virtual void set(const std::string & key, const std::shared_ptr<TResourceType> & resource) = 0;
			virtual std::shared_ptr<TResourceType> get(const std::string & key) const = 0;

		};

	}

}