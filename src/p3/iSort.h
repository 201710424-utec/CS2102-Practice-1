#include <vector>

void insertionSort(std::vector<int> &array) {
  int temp;
  int j;
  for (size_t i = 1; i < array.size() ; i++) {
    temp = array[i];
    j = i-1;
    while (j+1 > 0 && array[j] > temp) {
      array[j+1] = array[j];
      j--;
    }
    array[j+1] = temp;
  }
};
