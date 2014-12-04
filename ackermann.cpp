#include <iostream>

using namespace std;

int ackermann(int m, int n) {
	if (m == 0) {
		return n + 1;
	} else if (m > 0 && n == 0) {
		return ackermann(m-1, 1);
	} else if (m > 0 && n > 0) {
		return ackermann(m-1, ackermann(m, n-1));
	} else {
		return 0;
	}
}

int main() {
	int m, n;
	cout << "Enter m and n: ";
	cin >> m >> n;
	cout << "Ackermann(" << m << "," << n << "): " << endl;
	cout << ackermann(m, kn) << endl;
}