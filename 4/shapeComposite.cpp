#include "shapeComposite.h"
#include <memory>

namespace Shapes
{
	ShapeComposite::ShapeComposite(std::shared_ptr<Shape> shape1, std::shared_ptr<Shape> shape2, enum ShapeOperation operation) :
		shape1_(shape1), shape2_(shape2), operation_(operation) {};

	bool ShapeComposite::isIn(int x, int y) const
	{
		switch (operation_)
		{
		case INTERSECTION:
			return shape1_->isIn(x, y) && shape2_->isIn(x, y);
		case SUM:
			return shape1_->isIn(x, y) || shape2_->isIn(x, y);
		case DIFFERENCE:
			return shape1_->isIn(x, y) && !shape2_->isIn(x, y);
		}
	}
}
