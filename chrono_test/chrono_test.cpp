#include <chrono>
#include <cmath>
#include <fstream>
#include <iostream>

int main() {
  int numbers[1000];
  std::fstream info(
      "SomeFile.txt", std::ios_base::in | std::ios_base::out | std::ios_base::app);
  int duration = 0;
  if (info) {
    auto start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < 1000; i++) {
      numbers[i] = pow(i, 2);
    }
    auto end = std::chrono::high_resolution_clock::now();

    auto dur = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start)
                   .count();
    info << dur << std::endl;
  } else {
    std::cout << "file is not opened" << std::endl;
  }
  return 0;
}
