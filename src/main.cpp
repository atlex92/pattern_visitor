#include <iostream>
#include <memory>
#include <vector>
#include <assert.h>
#include "shapes.h"
#include "shape_serilization_visitor.h"

using namespace std;

int main() {

	Rectangle rect{10, 20, 15, 25};
	Circle cirlce{10, 20, 30};
	Triangle triangle{10, 20, 5, 5, -5, -5};

	std::unique_ptr<ShapeSerilizationVisitor> visitor{new SimpleTextSerilizator};

	rect.AcceptVisitor(visitor.get());
	cout << "Result:" << endl << visitor->Result() << endl;

	cirlce.AcceptVisitor(visitor.get());
	cout << "Result:" << endl << visitor->Result() << endl;

	triangle.AcceptVisitor(visitor.get());
	cout << "Result:" << endl << visitor->Result() << endl;

    return 0;
}
