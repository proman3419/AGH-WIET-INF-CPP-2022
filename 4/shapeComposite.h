#ifndef SHAPE_COMPOSITE_H
#define SHAPE_COMPOSITE_H

#include "shape.h"
#include <memory>

namespace Shapes
{
	enum ShapeOperation { INTERSECTION, SUM, DIFFERENCE };

	class ShapeComposite : public Shape
	{
	private:
		std::shared_ptr<Shape> shape1_;
		std::shared_ptr<Shape> shape2_;
		enum ShapeOperation operation_;

	public:
		ShapeComposite(std::shared_ptr<Shape> shape1, std::shared_ptr<Shape> shape2, enum ShapeOperation operation);

		virtual bool isIn(int x, int y) const override;
	};
}

#endif // SHAPE_COMPOSITE_H
