#include <iostream>
#include "tWayMS.h"

int main(int argc, char const *argv[]) {
  std::vector<int> A = {7,6,5,4,3,2,1,0};
  threeWayMergeSort(A, 0, A.size()-1);
  for (size_t i = 0; i < A.size(); i++) {
    std::cout << A[i] << ' ';
  }
  std::cout << '\n';
  return 0;
}
