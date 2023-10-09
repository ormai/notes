#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  vector<int> vec = {386, 942, 5, 365};
  vector<vector<int>> mat;

  if (mat.empty())
    cout << "mat is emtpy." << endl;

  vector<vector<int>>::size_type sizeOfMath = mat.size();

  cout << sizeOfMath << endl;

  vector<int> vec2 = vec;

  vector<int> vec3(10, -1); // vec3 = -1, -1, -1, -1, -1, -1, -1 -1, -1, -1

  if (vec2 == vec3)
    cout << "int vectors are equals" << endl;
  else if (vec2 > vec3)
    cout << "vec2 is bigger" << endl;

  vector<string> vec4(10); // vec4 = "", "", "", "", "", "", "", "", "", ""

  for (int i : vec3)
    cout << i << endl;

  int tmp;
  vector<int> vec5;

  return 0;
}
