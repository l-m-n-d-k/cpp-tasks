//lamp_curtains
#include <iostream>

using namespace std;

int main() {
  double time, lamp, curtains;

  cout << "write time, lamp and curtains in (0,1) format" << endl;
  cin >> time >> lamp >> curtains;
  int is_light;
    
  if ((time == 1 && curtains == 1) || lamp == 1) {
    is_light = 1;
  } else {
    is_light = 0;
  }

  if (is_light == 1){
    cout << "the room is bright";
  } else {
    cout << "the room is dark";
  }
 
  return 0;
}
