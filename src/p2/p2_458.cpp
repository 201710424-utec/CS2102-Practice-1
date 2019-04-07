#include <iostream>

int main(int argc, char const *argv[]) {
  std::string line;
  while (getline(std::cin, line)) {
    for (size_t i = 0; i < line.size(); i++) {
      line[i] = line[i]-7;
    }
    std::cout << line << '\n';
  }
}
