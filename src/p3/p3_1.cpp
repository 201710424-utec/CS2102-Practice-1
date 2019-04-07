#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include "iSort.h"
#include "mSort.h"

void randomIG (std::vector<int> &A, std::vector<int> &B, int size) {
  srand (time(NULL));
  int n;
  for (size_t i = 0; i < size; i++) {
    n = rand() % size + 1;
    A.push_back(n);
    B.push_back(n);
  }
}

void testPS(double &pmIS, double &pmMS, int testSize, int test) {
  double cValue = 1000000; // microseconds
  pmIS = 0;
  pmIS = 0;
  for (size_t i = 0; i < testSize; i++) {
    std::vector<int> A, B;
    randomIG(A, B, test);
    auto start = std::chrono::high_resolution_clock::now();
    insertionSort(A);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> timeIS = finish - start;
    start = std::chrono::high_resolution_clock::now();
    mergeSort(B, 0, B.size()-1);
    finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> timeMS = finish - start;
    pmIS += (timeIS.count()*cValue);
    pmMS += (timeMS.count()*cValue);
  }
  pmIS /= double(testSize);
  pmMS /= double(testSize);
}

int main(int argc, char const *argv[]) {
  int test = 1, bTest = 0;
  double pmIS, pmMS;
  int testSize = 100;
  std::fstream file;
  file.open("tests_1.txt", std::ios::out);
  file << "test\tmInsert\tmMerge\n";
  do {
    test++;
    testPS(pmIS, pmMS, testSize, test);
    file << test << "\t" << pmIS << "\t" <<pmMS << '\n';
  } while(pmIS < pmMS);
  bTest = test;
  do {
    for (size_t i = test+1; i < test+test/2; i++) {
      testPS(pmIS, pmMS, testSize, i);
      file << i << "\t" << pmIS << "\t" <<pmMS << '\n';
      if (pmIS < pmMS) {
        bTest = 0;
        test = i;
        break;
      }else if (bTest == 0) {
        bTest = i;
      }
    }
  } while(bTest == 0);
  file.close();
  std::cout << "Average input size for which the merge sort is an asymptotically better sorting algorithm is: " << bTest << '\n';
  return 0;
}
