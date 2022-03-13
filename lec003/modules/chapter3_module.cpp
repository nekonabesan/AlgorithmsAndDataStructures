using namespace std;
#include <iostream>
#include <vector>

int secondSmallestValue(std::vector<int> a) {
  std::vector<int> result(2);
  
  result[1] = 999999999;
  result[0] = 999999998;
  for (unsigned int i = 1; i < a.size(); i++) {
    if (a[i] < result[1]) {
      if (a[i] < result[0]) {
        result[1] = result[0];
        result[0] = a[i];
      } else {
        result[1] = a[i];
      }
    }
  }
  return result[1];
}
