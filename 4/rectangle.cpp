#include "rectangle.h"

namespace Shapes
{
	Rectangle::Rectangle(int xFrom, int yFrom, int xTo, int yTo) :
		xFrom_(xFrom), yFrom_(yFrom), xTo_(xTo), yTo_(yTo) {}

	bool Rectangle::isIn(int x, int y) const
	{
		return (xFrom_ <= x && x <= xTo_) && (yFrom_ <= y && y <= yTo_);
	}
}
