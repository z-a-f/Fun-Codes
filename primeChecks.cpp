
/* Assumption:
 * Every prime number reversed in binary is either a
 * prime, or a square of a prime
 */

#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

bool isPrime(unsigned num) {
  // return 0 if not prime
  // return 1 if prime
  // return 2 if square of a prime
  if (num == 2) return true;
  if (num < 2 || num % 2 == 0) return false;
  for (unsigned idx = 3, sq=sqrt(num); idx <= sq; idx+=2) {
	if (num % idx == 0)
	  return false;
  }
  return true;
}

vector<bool> sieve(unsigned max) {
  vector<bool> visited = vector<bool>(max, false);
  visited[0] = true;
  visited[1] = true;
  vector<bool> primes = vector<bool>(max, false);
  unsigned step = 0;
  for (unsigned ii = 2, sq = sqrt(max); ii <= sq; ii++) {
	if (visited[ii]) continue;
	visited[ii] = true;
	primes[ii] = true;
	step = ii;
	// Strike out
	for (unsigned jj = 1; jj <= max/step; jj++) {
	  visited[jj*step] = true;
	}
  }

  // Get the ones that are not striked out
  for (unsigned ii = sqrt(max); ii < max; ii++) {
	if (!visited[ii]) primes[ii] = true;
  }
  return primes;
}

bool isSquare(unsigned num) {
  unsigned temp = sqrt(num);
  if (temp*temp == num) return true;
  else return false;
}

bool isPrimeSquared(unsigned num) {
  unsigned temp = sqrt(num);
  if (temp*temp != num) return false;
  if (isPrime(temp)) return true;
  return false;
}

unsigned reverseBin(unsigned num) {
  unsigned temp = 0;
  while (num) {
	temp = (temp<<1) + (num%2);
	num = num >> 1;
  }
  return temp;
}

void printPrimeFactors(unsigned num) {
  cout << "[ ";
  cout << 1 << " ";
  unsigned counter = 2;
  while (num % counter == 0) {
	cout << counter << " ";
	num = num / counter;
  }
  unsigned sq;
  for (counter = 3, sq = sqrt(num); counter <= sq; counter += 2) {
	while (num % counter == 0) {
	  cout << counter << " ";
	  num = num / counter;
	}
  }
  cout << "]";
}

int main() {
  // Create the list of all the prime numbers smaller than some big number:
  unsigned static MAX_NUMS = 10000;
  vector<bool> primes;
  primes = sieve(MAX_NUMS);
  // cout << primes.size() << endl;
  /* for (unsigned ii = 0; ii < MAX_NUMS; ii++){
	if (primes[ii]) { cout << ii << ", "; }
	}
  cout << endl;
  */
  unsigned temp = 0;
  for (unsigned ii = 3; ii < MAX_NUMS; ii++){
	if (!primes[ii]) continue;
	temp = reverseBin(ii);
	cout << ii << " <-> " << temp;
	if (!isPrime(temp) && !isPrimeSquared(temp)) {
	  cout << "\t";
	  printPrimeFactors(temp);
	  cout << "\tWoops!";
	  // break;
	}
	cout << endl;
  }
  cout << endl;
}
