#include "shapes.h"
#include "shape_serilization_visitor.h"

void Rectangle::AcceptVisitor(ShapeSerilizationVisitor* visitor) {
    visitor->Visit(*this);
}

void Circle::AcceptVisitor(ShapeSerilizationVisitor* visitor) {
    visitor->Visit(*this);
}

void Triangle::AcceptVisitor(ShapeSerilizationVisitor* visitor) {
    visitor->Visit(*this);
}