#include <iostream>
using std::cout, std::endl;
#include <vector>
using std::vector;
#include <algorithm>
using std::sort;
#include <cmath> // M_PI

class FiguraGeometrica {
public:
  virtual double perimetro() const = 0; // perimetro dell
  virtual double area() const = 0;      // area della figura
  virtual void stampa() const = 0;
};

class Cerchio : public FiguraGeometrica {
private:
  double raggio{0.0};

public:
  Cerchio() = default;
  Cerchio(const double &_raggio) : raggio(_raggio) {}
  Cerchio(const Cerchio &cerchio) : raggio(cerchio.raggio) {}

  double perimetro() const { return 2 * M_PI * raggio; }
  double area() const { return M_PI * raggio * raggio; }

  void stampa() const {
    cout << "Cerchio, raggio: " << raggio << " mm." << endl;
  }
};

class Rettangolo : public FiguraGeometrica {
private:
  double latoMaggiore{0.0}, latoMinore{0.0};

public:
  Rettangolo() {}
  Rettangolo(const double &_latoMaggiore, const double &_latoMinore)
      : latoMaggiore(_latoMaggiore), latoMinore(_latoMinore) {}
  Rettangolo(const Rettangolo &rettangolo)
      : latoMaggiore(rettangolo.getLatoMaggiore()),
        latoMinore(rettangolo.getLatoMinore()) {}

  double getLatoMaggiore() const { return latoMaggiore; }
  double getLatoMinore() const { return latoMinore; }
  double perimetro() const { return 2 * latoMaggiore + 2 * latoMinore; }
  double area() const { return latoMaggiore * latoMinore; }

  void stampa() const {
    cout << "Rettangolo " << getLatoMaggiore() << 'x' << getLatoMinore()
         << " mm." << endl;
  }
};

class Quadrato : public Rettangolo {
public:
  Quadrato() = default;
  Quadrato(const double &_lato) : Rettangolo(_lato, _lato) {}
  Quadrato(const Quadrato &quadrato)
      : Rettangolo(quadrato.getLatoMaggiore(), quadrato.getLatoMinore()) {}

  double perimetro() const { return 4 * getLatoMaggiore(); }
  double area() const { return getLatoMaggiore() * getLatoMinore(); }

  void stampa() const {
    cout << "Quadrato, lato: " << getLatoMaggiore() << " mm." << endl;
  }
};

int main() {
  Cerchio c(8.756);
  Cerchio d(14.31);

  Rettangolo r(40, 15);
  Rettangolo s(20, 10);

  Quadrato q(20);

  vector<FiguraGeometrica *> figure;
  figure.push_back(&c);
  figure.push_back(&d);
  figure.push_back(&r);
  figure.push_back(&s);
  figure.push_back(&q);

  sort(figure.begin(), figure.end(),
       [](FiguraGeometrica *a, FiguraGeometrica *b) {
         return (a->area() / a->perimetro()) > (b->area() / b->perimetro());
       });

  for (FiguraGeometrica *figura : figure)
    figura->stampa();

  return 0;
}
