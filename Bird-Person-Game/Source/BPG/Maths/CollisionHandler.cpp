#include <BPG/Maths/CollisionHandler.hpp>

#include <SFML/Graphics/Rect.hpp>

namespace Maths 
{

	FVector2 CollisionHandler::getOverlap(const BoundaryComponent & source, const BoundaryComponent & destination) {
		const sf::FloatRect srcBoundary = source.getBoundary();
		const sf::FloatRect destBoundary = destination.getBoundary();

		const float srcX = srcBoundary.left, srcY = srcBoundary.top;
		const float srcW = srcBoundary.width, srcH = srcBoundary.height;

		const float destX = destBoundary.left, destY = destBoundary.top;
		const float destW = destBoundary.width, destH = destBoundary.height;

		const float srcCenterX = srcX + srcW / 2.f;
		const float srcCenterY = srcY + srcH / 2.f;

		const float destCenterX = destX + destW / 2.f;
		const float destCenterY = destY + destH / 2.f;

		const float xDiff = std::abs(destCenterX - srcCenterX);
		const float yDiff = std::abs(destCenterY - srcCenterY);

		if (xDiff > yDiff)
		{
			float overlapX = 0.f;
			
			// Horizontal pushen
			if (srcCenterX > destCenterX)
			{
				// Nach rechts pushen
				overlapX = srcW / 2.f + destW / 2.f - xDiff;
			}
			else
			{
				// Nach links pushen
				overlapX = -(srcW / 2.f + destW / 2.f - xDiff);
			}

			return FVector2(overlapX, 0.f);
		}
		else
		{
			float overlapY = 0.f;

			// Vertikal pushen
			if (srcCenterY > destCenterY)
			{
				// Nach unten pushen
				overlapY = srcH / 2.f + destH / 2.f - yDiff;
			}
			else
			{
				// Nach oben pushen
				overlapY = -(srcH / 2.f + destH / 2.f - yDiff);
			}

			return FVector2(0.f, overlapY);
		}

	};

}