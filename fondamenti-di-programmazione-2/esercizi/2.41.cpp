#include <iostream>
#include <string>
using namespace std;

struct Sales_data {
  string bookNo;
  unsigned units_sold;
  float revenue;
};

int main() {
  Sales_data data1, data2;
  double price = 0;

  cin >> data1.bookNo >> data1.units_sold >> price;
  data1.revenue = data1.units_sold * price;

  cin >> data2.bookNo >> data2.units_sold >> price;
  data2.revenue = data2.units_sold * price;

  if (data1.bookNo == data2.bookNo) {
    unsigned totalSold = data1.units_sold + data2.units_sold;
    double totalRevenue = data1.revenue + data2.revenue;

    cout << data1.bookNo << ' ' << totalSold << ' ' << totalRevenue << ' ';

    if (totalSold != 0)
      cout << totalRevenue / totalSold << endl;
    else
      cout << "(no sales)" << endl;
    return 0;
  } else {
    cerr << "Data must refer to the same ISBN" << endl;
    return -1;
  }
}
