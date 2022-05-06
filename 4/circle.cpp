#include "circle.h"

#include <math.h>

namespace Shapes
{
	Circle::Circle(int x, int y, unsigned int r) :
		x_(x), y_(y), r_(r) {}

	bool Circle::isIn(int x, int y) const
	{
		return pow((double)x - x_, 2) + pow((double)y - y_, 2) <= r_ * r_;
	}
}
