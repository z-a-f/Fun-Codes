#include <stdio.h>

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

int main(void) {
  int m = 4, n = 1;
  printf ("Ackermann(%d,%d): ", m, n);
  printf ("%d\n", ackermann(m, n));

}
