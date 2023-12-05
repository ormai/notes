#include <iostream>
using std::istream, std::ostream;

#include <string>
using std::string;


class Person {
  static int iAmAlways;
  string name{""};
  string address{""};
  mutable int iMuteOften{0}; // modifiable even if Person object is const

public:
  Person() = default;
  Person(const string &_name, const string &_address)
      : name(_name), address(_address) {}

  explicit Person(const string &_name) : name(_name) {}
  // explicit makes it so this constructor can't be used for implicit conversion

  Person(const Person &p) : name(p.name), address(p.address) {}

  string getName() const { return name; }
  string getAddress() const { return address; }
  Person &setName(const string &_name) {
    name = _name;
    return *this;
  }
  Person &setAddress(const string &_address) {
    address = _address;
    return *this;
  }
};

int Person::iAmAlways = 3; // definition can't be inline

istream &read(istream &is, Person &person) {
  string address, name;
  is >> address >> name;
  person.setAddress(address);
  person.setName(name);
  return is;
}

ostream &print(ostream &os, const Person &person) {
  os << person.getName() << ", " << person.getAddress();
  return os;
}

int main() {
  Person Bjarne;
  Bjarne.setName("Bjarne").setAddress("Switzerland Street");
}
