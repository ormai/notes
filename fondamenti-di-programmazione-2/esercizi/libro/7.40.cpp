#include <string>
using std::string;

class Book {
private:
  string title{""};
  string author{""};
  string isbn{""};
  unsigned pages{0};
  double price{0.0};

public:
  Book() = default;
  Book(const string &_title, const string &_author, const string &_isbn,
       const unsigned &_pages, const double &_price)
      : title(_title), author(_author), isbn(_isbn), pages(_pages),
        price(_price) {}
  Book(const string &_title, const string &_author)
      : title(_title), author(_author) {}
};

class Date {
private:
  string weekday{""};
  unsigned char day{0};
  unsigned char month{0};
  unsigned year{0};

public:
  Date() = default;
  Date(const string &_weekday, const unsigned char &_day,
       const unsigned char &_month, const unsigned &_year)
      : weekday(_weekday), day(_day), month(_month), year(_year) {}
  Date(const unsigned char &_day, const unsigned char &_month)
      : day(_day), month(_month) {}
};

class Employee {
private:
  string name{""};
  string id{""};
  string role{""};

public:
  Employee() = default;
  Employee(const string &_name, const string &_id, const string &_role)
      : name(_name), id(_id), role(_role) {}
};

class Vehicle {
public:
  string model{""};
  string type{""};
  unsigned char wheels{0};
  unsigned char passengerSeats{0};

public:
  Vehicle() = default;
  Vehicle(const string &_model, const string &_type,
          const unsigned char &_wheels, const unsigned char &_passengerSeats)
      : model(_model), type(_type), wheels(_wheels),
        passengerSeats(_passengerSeats) {}
  Vehicle(const string &_model, const unsigned char &_wheels)
      : model(_model), wheels(_wheels) {}
};
