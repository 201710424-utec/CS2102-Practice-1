#include <iostream>
#include <vector>
#include <string>

typedef std::vector<std::string> square;

bool compareSquares(square bSquare, square sSquare, int dH, int dV) {
  for (size_t i = 0; i < sSquare.size(); i++) {
    for (size_t j = 0; j < sSquare.size(); j++) {
      if (bSquare[i+dV][j+dH] != sSquare[i][j]) {
        return false;
      }
    }
  }
  return true;
}

square turnSquare(square sSquare) {
  square tSquare;
  for (size_t i = 0; i < sSquare.size(); i++) {
    std::string line = "";
    for (size_t j = sSquare.size(); j > 0; j--) {
      line += sSquare[j-1][i];
    }
    tSquare.push_back(line);
  }
  return tSquare;
}

void fitInSquare(square bSquare, square sSquare, int dH, int dV, std::vector<int> &nCondidences) {
  for (size_t i = 0; i < 4; i++) {
    if (compareSquares(bSquare, sSquare, dH, dV)) {
      nCondidences[i]++;
    }
    sSquare = turnSquare(sSquare);
  }
}

void scanSquares(square bSquare, square sSquare, std::vector<int> &nCondidences){
  int desplacements = bSquare.size()-sSquare.size()+1;
  for (size_t dV = 0; dV < desplacements; dV++) {
    for (size_t dH = 0; dH < desplacements; dH++) {
      fitInSquare(bSquare, sSquare, dH, dV, nCondidences);
    }
  }
}

int main(int argc, char const *argv[]) {
  int n = 0, N = 0, tests = 0;
  std::cin >> N >> n;
  std::string line;
  std::vector<std::vector<int>> output;
  while (N != 0 && n != 0) {
    tests++;
    square bSquare, sSquare;
    std::vector<int> nCondidences = {0,0,0,0};
    for (size_t i = 0; i < N; i++) {
      std::cin >> line;
      bSquare.push_back(line);
    }
    for (size_t i = 0; i < n; i++) {
      std::cin >> line;
      sSquare.push_back(line);
    }
    scanSquares(bSquare, sSquare, nCondidences);
    output.push_back(nCondidences);
    std::cin >> N >> n;
  }
  for (size_t i = 0; i < tests; i++) {
    for (size_t j = 0; j < 4; j++) {
      std::cout << output[i][j];
      if (j != 3) {
        std::cout << ' ';
      }
    }
    std::cout << '\n';
  }
}
