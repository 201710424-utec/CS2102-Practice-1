#include <limits>
#include <vector>

void merge(std::vector<int> &A, int p, int q, int r){
  int n1 = q-p+1;
  int n2 = r-q;
  int R[n1+1], L[n2+1];
  for (size_t i = 0; i < n1; i++) {
    R[i] = A[p+i];
  }
  for (size_t i = 0; i < n2; i++) {
    L[i] = A[q+1+i];
  }
  R[n1] = std::numeric_limits<int>::max();
  L[n2] = std::numeric_limits<int>::max();
  int i = 0, j = 0;
  for (size_t n = p; n <= r; n++) {
    if (R[i] <= L[j]) {
      A[n] = R[i];
      i++;
    }else{
      A[n] = L[j];
      j++;
    }
  }
}

void mergeSort(std::vector<int> &A, int p, int r){
  if (p < r) {
    int q;
    q = (p+r)/2;
    mergeSort(A,p,q);
    mergeSort(A,q+1,r);
    merge(A,p,q,r);
  }
}
