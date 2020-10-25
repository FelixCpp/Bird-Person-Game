#pragma once

namespace Utils
{

	struct StaticObject {
	
		StaticObject() = delete;
		virtual ~StaticObject() = default;

		StaticObject(const StaticObject &) = delete;
		StaticObject(StaticObject &&) = delete;
		StaticObject & operator=(const StaticObject &&) = delete;
		StaticObject & operator=(StaticObject &&) = delete;

	};

}