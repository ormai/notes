#include <iostream>

class Circle {
  double radius;

public:
  Circle(double r) : radius(r) {}
  double area() { return radius * 3.14; }
};

class Cylinder {
  Circle base; // va inizializzato per forza perché non ha default
  double height;

public:
  Cylinder(double r, double h) : base(r) { height = h; }
  double volume() { return base.area() * height; }
};

int main() {
  Cylinder foo(10, 20);

  std::cout << foo.volume() << std::endl;
  return 0;
}
