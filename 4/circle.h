#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

namespace Shapes
{
	class Circle : public Shape
	{
	private:
		int x_;
		int y_;
		unsigned int r_;

	public:
		Circle(int x, int y, unsigned int r);

		int x() const { return x_; }
		int y() const { return y_; }
		unsigned int getRadius() const { return r_; }

		virtual bool isIn(int x, int y) const override;
	};
}

#endif // CIRCLE_H
