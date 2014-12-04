
#include <set>
#include <vector>

template <typename T>
using setset = typename std::vector< std::set<T> >;

template <typename T>
setset<T> PowerSet(std::set<T> S) {
  //if (S.empty()) {
  return setset<T>(S.begin(), S.end());
    //}
}


int main() {
  setset<int> test;
  std::set<int> T;
  PowerSet(T);
}
