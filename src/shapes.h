#pragma once

class ShapeSerilizationVisitor;

struct Shape {
    virtual ~Shape() = default;
    Shape(const int x, const int y) : x_{x}, y_{y} {}

    virtual const char* Name() const = 0;
    virtual void AcceptVisitor(ShapeSerilizationVisitor* visitor) = 0;

    int X() const {
        return x_;
    }

    int Y() const {
        return y_;
    }
private:
    int x_{};
    int y_{};
};

struct Rectangle : Shape{
    Rectangle(const int x, const int y, const int w, const int h) : Shape(x, y), w_{w}, h_{h} {}

    const char* Name() const override {
        return "Rectangle";
    }

    int Width() const {
        return w_;
    }

    int Height() const {
        return h_;
    }

    void AcceptVisitor(ShapeSerilizationVisitor* visitor) override;
private:
    int w_{};
    int h_{};
};

struct Circle : Shape{
    Circle(const int x, const int y, const int r) : Shape(x, y), r_{r} {}

    const char* Name() const override {
        return "Circle";
    }

    int Radius() const {
        return r_;
    }

    void AcceptVisitor(ShapeSerilizationVisitor* visitor) override;
private:
    int r_{};
};

struct Triangle : Shape{
    Triangle(const int x, const int y, const int x2, const int y2, const int x3, const int y3) : 
        Shape(x, y), offs_x_2_{x2}, offs_y_2_ {y2}, offs_x_3_{x3}, offs_y_3_{y3} {}

    const char* Name() const override {
        return "Triangle";
    }

    int SecondPointOffsetX() const {
        return offs_x_2_;
    }

    int SecondPointOffsetY() const {
        return offs_y_2_;
    }

    int ThirdPointOffsetX() const {
        return offs_x_3_;
    }

    int ThirdPointOffsetY() const {
        return offs_y_3_;
    }

    void AcceptVisitor(ShapeSerilizationVisitor* visitor) override;
private:
    int offs_x_2_{};
    int offs_y_2_{};
    int offs_x_3_{};
    int offs_y_3_{};

};