#pragma once
#include <string>

class Shape;
class Rectangle;
class Circle;
class Triangle;

struct ShapeSerilizationVisitor {
    virtual ~ShapeSerilizationVisitor() = default;
    virtual void Visit(const Rectangle& shape) = 0;
    virtual void Visit(const Circle& shape) = 0;
    virtual void Visit(const Triangle& shape) = 0;

    std::string Result() const {
        return res_;
    }
protected:
    std::string res_{};
};

struct SimpleTextSerilizator : ShapeSerilizationVisitor {

    void Visit(const Rectangle& shape) override {
        CommonVisit(shape);
        res_.append(", width = ");
        res_.append(std::to_string(shape.Width()));
        res_.append(", height = ");
        res_.append(std::to_string(shape.Height()));
    }

    void Visit(const Circle& shape) override {
        CommonVisit(shape);
        res_.append(", radius = ");
        res_.append(std::to_string(shape.Radius()));
    }

    void Visit(const Triangle& shape) override {
        CommonVisit(shape);
        res_.append(", x2 = ");
        res_.append(std::to_string(shape.SecondPointOffsetX()));
        res_.append(", y2 = ");
        res_.append(std::to_string(shape.SecondPointOffsetY()));
        res_.append(", x3 = ");
        res_.append(std::to_string(shape.ThirdPointOffsetX()));
        res_.append(", y3 = ");
        res_.append(std::to_string(shape.ThirdPointOffsetY()));
    }

    void CommonVisit(const Shape& shape) {
        res_.clear();
        res_.append("Shape: ");
        res_.append(shape.Name());
        res_.append(", x = ");
        res_.append(std::to_string(shape.X()));
        res_.append(", y = ");
        res_.append(std::to_string(shape.Y()));        
    }
};