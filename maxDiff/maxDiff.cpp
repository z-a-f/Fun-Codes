#include <iostream>

//template <typename T, unsigned S>
//inline unsigned ArSize(const T (&v)[S]) { return S; }

using namespace std;

// Bruteforce approach
int maxDiff1(int ar[], int n) {
  // Time complexity: O(n^2)
  // Space complexity: O(1)
  int max_diff = 0;
  // int n = size(&ar);
  // int n = sizeof(ar) / sizeof(ar[0]);
  for (int ii = 0; ii < n; ii++) {
	// traversal through all elements
	for (int jj = ii+1; jj < n; jj++) {
	  if (ar[jj] - ar[ii] > max_diff)
		max_diff = ar[jj] - ar[ii];
	}
  }
  return max_diff;
}

// Find by keeping track the maximum difference so far
// as well as the current minimum so far
int maxDiff2(int ar[], int n) {
  // Time complexity: O(n)
  // Space complexity: O(1)
  int max_diff = 0;
  int min = ar[0];
  for (int ii = 1; ii < n; ii++) {
	if (max_diff < ar[ii] - min)
	  max_diff = ar[ii] - min;
	if (ar[ii] < min)
	  min = ar[ii];
  }
  return max_diff;
}

int main() {
  int ar1[] = {1, 2, 90, 10, 110};
  int ar2[] = {100, 180, 260, 310, 40, 535, 695};
 
  cout << "Bruteforce approach:\n";
  cout << maxDiff1(ar1, 5) << endl;
  cout << maxDiff1(ar2, 7) << endl;

  cout << "Second approach:\n";
  cout << maxDiff2(ar1, 5) << endl;
  cout << maxDiff2(ar2, 7) << endl;
}
