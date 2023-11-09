#include <initializer_list>
#include <iostream>
#include <map>
#include <string>
#include <utility>

template <class X, class Y> class Doublemap {
  std::map<X, Y> data;

public:
  Doublemap() = default;
  Doublemap<X, Y>(std::initializer_list<std::pair<X, Y>> l) {
    for (std::pair<X, Y> e : l)
      data.insert(e);
  }

  Y operator[](const X &k) const { return data.at(k); }

  X operator[](const Y &v) const {
    for (std::pair<X, Y> e : data)
      if (e.second == v)
      return e.first;

    return X(); // costruisce un oggetto vuoto
  }
};

int main() {
  Doublemap<std::string, unsigned> prezzi = {
      {"Latte", 1}, {"Pane", 2}, {"Sale", 5}};

  std::cout << prezzi["Latte"] << std::endl;
  std::cout << prezzi[5] << std::endl;

  return 0;
}
