#include <iostream>
using std::cout, std::endl;

#include <string>
using std::string;

// function restituisce il riferimento ad un array di 2 stringhe.
// Il suo unico parametro è un riferimento ad un array di 2 stringhe.

// string &function()[2]; scrivendo così si avrebbe che function restituisce
// un array contenente 2 riferimenti a stringhe.
string (&function(string (&arr)[2]))[2] {
  arr[0] = "ciao";
  arr[1] = "mondo";
  return arr;
}

int main() {
  string myStrings[2]{"hello", "world"};

  cout << myStrings[0] << ", " << myStrings[1] << endl;
  cout << function(myStrings)[0] << endl;
  function(myStrings)[0] = "Bonjour";
  // La chiamata a function() restituisce un riferimento, quindi un lvalue,
  // che è assegnabile.
  cout << myStrings[0] << ", " << myStrings[1] << endl;

  return 0;
}
