#include <iostream>
#include <cmath>
#include <chrono>

int main() {
	int numbers[1000];

  auto start = std::chrono::high_resolution_clock::now();
  for (size_t i = 0; i < 1000; i++) {
       numbers[i] = i;
  }
  for (size_t i = 0; i < 1000; i++) {
    numbers[i] = pow(numbers[i], 2);
  }
  auto end = std::chrono::high_resolution_clock::now();

  auto dur = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start)
                 .count();

  std::cout << dur;
	return 0;
}
