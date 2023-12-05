#include <iostream>
using std::cout, std::endl;
#include <string>
using std::string;

class SalesData {
private:
  string bookNumber{""};
  unsigned unitsSold{0};
  double price{0.0};

public:
  SalesData() { cout << "Default constructor" << endl; }
  SalesData(const string &_bookNumber, const unsigned &_unitsSold,
            const double &_price)
      : bookNumber(_bookNumber), unitsSold(_unitsSold), price(_price) {
    cout << "Full argument constructor" << endl;
  }
  SalesData(const string &_bookNumber) : SalesData(_bookNumber, 0, 0) {
    cout << "Only first argument delegating constructor" << endl;
  }
};

int main() {
  SalesData a;
  SalesData b{"97888123419", 3, 24.50};
  SalesData c{"97888808764"};

  return 0;
}
