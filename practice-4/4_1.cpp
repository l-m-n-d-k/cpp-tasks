//task 4_1
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void ifRectangle() {
  cout << "enter width and height" << endl;

  float width, height;
  cin >> width >> height;

  if (width <= 0 or height <= 0) {
    cout << "width or height <= 0" << endl;
  }
  else {
    cout << "rectangle area: " << width * height << endl;
  }
}

void ifTriangle() {
  cout << "enter base and height" << endl;

  float base, height;
  cin >> base >> height;

  if (base <= 0 or height <= 0) {
    cout << "base or height <= 0" << endl;
  }
  else {  
    cout << "triangle area: " << (base * height) / 2 << endl;
  }
}

void ifCircle() {
  cout << "enter radius" << endl;

  float radius;
  cin >> radius;

  if (radius <= 0) {
    cout << "radius <= 0" << endl;
  }
  else {
    cout << "circle area: " << M_PI * pow(radius, 2) << endl;
  }
}

int main() {
  string type;
  cout << "enter shape type:" << endl;
  cin >> type;

  if (type == "rectangle") {
    ifRectangle();
  }
  else if (type == "triangle") {
    ifTriangle();
  }
  else if (type == "circle") {
    ifCircle();
  }
  else {
    cout << "this is not rectangle/triangle/circle" << endl;
  }

  return 0;
}
