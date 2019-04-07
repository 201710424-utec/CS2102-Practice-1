#include <vector>

void swapElements(std::vector<int> &array, size_t posA, size_t posB) {
  int temp = 0;
  temp = array[posA];
  array[posA] = array[posB];
  array[posB] = temp;
};

void selectionSort(std::vector<int> &array) {
  int size = array.size();
  int minIndex;
  for (size_t i = 0; i < size-1; i++) {
    minIndex = i;
    for (size_t j = i; j < size; j++) {
      if (array[minIndex] > array[j]) {
        minIndex = j;
      }
    }
    swapElements(array, i, minIndex);
  }
}
