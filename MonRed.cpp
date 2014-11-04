/*
 * Multiplication using Mongomery reduction
 * Working only with the long long integers
 *
 * Calculates c = a * b (mod N), where N is big
 */

#include <iostream>

typedef long long LL;

unsigned powOfTwo(LL N) {
  // Not very efficient - iterate through 128 powers of 2:
  for (int i = 0; i < 128; i++) {
    if ((1 << i) >= N)
      return i;
  }
  return 0;
}


LL montMult(LL a, LL b, LL N) {
  unsigned r = powOfTwo (N);
  if (1<<R == N) {
    return ((a * b) % N);
  }
  
  

  LL aR = a << r;
  LL bR = b << r;
  LL cR = ((aR * bR) >> r) % N;

  std::cout << "R: " << R << std::endl;
  std::cout << "aR: " << aR << std::endl;
  std::cout << "bR: " << bR << std::endl;
  std::cout << "cR: " << cR << std::endl;

  return (cR >> R) % N;
}


int main() {
  std::cout << montMult(3,5,7) << std::endl;
}
