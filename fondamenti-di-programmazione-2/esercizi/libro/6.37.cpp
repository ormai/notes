#include <string>
using std::string;

string (&function(string (&arr)[2]))[2];

typedef string arrTwoStr[2];
// Il tipo arrTwoStr è sinonimo di array di due stringhe
arrTwoStr &function(arrTwoStr &arr); // type alias

auto function(string (&arr)[2]) -> string (&)[2]; // trailing return

string strs[2];
decltype(strs) &function(string (&arr)[2]);
