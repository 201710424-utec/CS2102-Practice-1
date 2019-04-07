#include "tWayM.h"

void threeWayMergeSort(std::vector<int> &A, int p, int s){
  if (p < s) {
    int q, r;
    q = p+(s-p+1)/3-1;
    r = q+(s-p)/3+1;
    threeWayMergeSort(A,p,q);
    threeWayMergeSort(A,q+1,r);
    threeWayMergeSort(A,r+1,s);
    merge(A,p,q,r,s);
  }
}
