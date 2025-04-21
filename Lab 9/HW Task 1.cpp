#include <iostream>
using namespace std;

class Geometry {
public:
    virtual void calculateArea() = 0;
    virtual ~Geometry() {}
};

class Box : public Geometry {
private:
    double lengthVal, widthVal;
public:
    Box(double l, double w) : lengthVal(l), widthVal(w) {}
    void calculateArea() override {
        double area = lengthVal * widthVal;
        cout << "Box Area = " << area << endl;
    }
};

class Pyramid : public Geometry {
private:
    double baseLength, heightVal;
public:
    Pyramid(double b, double h) : baseLength(b), heightVal(h) {}
    void calculateArea() override {
        double area = 0.5 * baseLength * heightVal;
        cout << "Pyramid Area = " << area << endl;
    }
};

int main() {
    Geometry *shape1, *shape2;

    shape1 = new Box(5.0, 10.0);
    shape2 = new Pyramid(4.0, 6.0);

    shape1->calculateArea();
    shape2->calculateArea();

    delete shape1;
    delete shape2;

    return 0;
}

