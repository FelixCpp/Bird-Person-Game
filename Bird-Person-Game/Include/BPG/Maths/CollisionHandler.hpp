#pragma once

#include <BPG/Utils/StaticObject.hpp>
#include <BPG/Maths/BoundaryComponent.hpp>
#include <BPG/Maths/Vector2.hpp>

namespace Maths
{

	struct CollisionHandler : Utils::StaticObject {

		static FVector2 getOverlap(const BoundaryComponent & source, const BoundaryComponent & destination);

	};

}