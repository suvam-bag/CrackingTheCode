/*Virtual Functions*/

#include <iostream>

using namespace std;

class Shape {
public:
	int edge;
	virtual int circumference() {
		cout << "shape of class\n";
		return 0;
	}
};

class Triangle : public Shape {
public:
	int circumference () {
		cout << "shape is Triangle\n";
		return 0;
	}
};

int main() {
	Shape *x = new Shape();
	x->circumference();
	Shape *y = new Triangle();
	y->circumference();
	return 0;
}


/*In the previous example, circumference is a virtual function in the Shape class, so it becomes virtual in each of the derived class (Triangle).
C++ non-virtual function calls are resolved at compile time with static binding, while virtual function calls are resolved at runtime with dynamic bonding. */ 