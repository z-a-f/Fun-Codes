// The goal is to fill the following irregular box with
// numbers from 1-8. The numbers that differ only by 1
// are not allowed to be next to each other (hor, ver, or diag)
//   The box looks like that (numbers indicate the positions):
//    _
//  _|0|_
// |1|2|3|
// |4|5|6|
//   |7|

// This program runs an extensive search

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool tryPermutation(int myints[8]) {
  if (
      // '0' box:
      (abs(myints[0] - myints[1]) == 1) ||
      (abs(myints[0] - myints[2]) == 1) ||
      (abs(myints[0] - myints[3]) == 1) ||
      // '1' box:
      (abs(myints[1] - myints[2]) == 1) ||
      (abs(myints[1] - myints[4]) == 1) ||
      (abs(myints[1] - myints[5]) == 1) ||
      // '2' box:
      (abs(myints[2] - myints[3]) == 1) ||
      (abs(myints[2] - myints[4]) == 1) ||
      (abs(myints[2] - myints[5]) == 1) ||
      (abs(myints[2] - myints[6]) == 1) ||
      // '3' box:
      (abs(myints[3] - myints[5]) == 1) ||
      (abs(myints[3] - myints[6]) == 1) ||
      // '4' box:
      (abs(myints[4] - myints[5]) == 1) ||
      (abs(myints[4] - myints[7]) == 1) ||
      // '5' box:
      (abs(myints[5] - myints[6]) == 1) ||
      (abs(myints[5] - myints[7]) == 1) ||
      // '6' box:
      (abs(myints[6] - myints[7]) == 1)
      ) return false;
  else return true;
}

void printPermutation(int myints[8]) {
  for (int i = 0; i < 8; i++) {
    cout << myints[i] << ' ';
  }
  cout << endl;
}

int main() {
  int myints[] = {1,2,3,4,5,6,7,8};
  sort(myints, myints+3);
  do {
    cout << "Trying permutation: ";
    printPermutation(myints);
    if (tryPermutation(myints))
      break;
  } while ( std::next_permutation(myints,myints+8) );
  cout << "Found permutation: ";
  printPermutation(myints);
}
