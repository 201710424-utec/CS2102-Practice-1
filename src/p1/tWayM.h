#include <limits>
#include <vector>

void merge(std::vector<int> &A, int p, int q, int r, int s){
  int n1 = q-p+1;
  int n2 = r-q;
  int n3 = s-r;
  int R[n1+1], M[n2+1], L[n3+1];
  for (size_t i = 0; i < n1; i++) {
    R[i] = A[p+i];
  }
  for (size_t i = 0; i < n2; i++) {
    M[i] = A[q+1+i];
  }
  for (size_t i = 0; i < n3; i++) {
    L[i] = A[r+1+i];
  }
  R[n1] = std::numeric_limits<int>::max();
  M[n2] = std::numeric_limits<int>::max();
  L[n3] = std::numeric_limits<int>::max();
  int i = 0, j = 0, k = 0;
  for (size_t n = p; n <= s; n++) {
    if (R[i] <= M[j]) {
      if (R[i] <= L[k]) {
        A[n] = R[i];
        i++;
      }else{
        A[n] = L[k];
        k++;
      }
    }else if (M[j] <= L[k]) {
      A[n] = M[j];
      j++;
    }else{
      A[n] = L[k];
      k++;
    }
  }
}
