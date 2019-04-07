#include <iostream>

void orderPair(int &iPair, int &jPair){
  if (iPair > jPair) {
    int temp;
    temp = iPair;
    iPair = jPair;
    jPair = temp;
  }
}

int main(int argc, char const *argv[]) {
  int maxCycle = 0, cycle = 0;
  int iPar = 0, jPar = 0, cValue = 0;
  while (std::cin >> iPar >> jPar) {
    std::cout << iPar << ' ' << jPar << ' ' ;
    orderPair(iPar, jPar);
    maxCycle = 0;
    for (int i = iPar; i <= jPar; i++) {
      cValue = i;
      cycle = 1;
      while (cValue != 1) {
        if (cValue%2 == 1) {
          cValue = 3*cValue+1;
        }else{
          cValue = cValue/2;
        }
        cycle++;
      }
      if (cycle > maxCycle) {
        maxCycle = cycle;
      }
    }
    std::cout << maxCycle << '\n';
  }
  return 0;
}
