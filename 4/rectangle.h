#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

namespace Shapes
{
	class Rectangle : public Shape
	{
	private:
		int xFrom_;
		int yFrom_;
		int xTo_;
		int yTo_;

	public:
		Rectangle(int xFrom, int yFrom, int xTo, int yTo);

		int x() const { return xFrom_; }
		int y() const { return yFrom_; }
		int xTo() const { return xTo_; }
		int yTo() const { return yTo_; }

		virtual bool isIn(int x, int y) const override;
	};
}

#endif // RECTANGLE_H
