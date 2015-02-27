#include <iostream>

using namespace std;

int main() {
  for (int i = 1; i <= 100; i++) {
    cout << i << ". ";
    if (i % 3 == 0 || i % 5 == 0) {
      if (i % 3 == 0)
	cout << "Crackle";
      if (i % 5 == 0)
	cout << "Pop";
    } else {
      cout << i;
    }
    cout << endl;
  }
}
