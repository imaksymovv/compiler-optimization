﻿#include <chrono>
#include <cmath>
#include <fstream>
#include <iostream>

int main() {
  int numbers[1000];
  std::fstream info(
      "info.txt", std::ios_base::in | std::ios_base::out | std::ios_base::app);
  int duration = 0;
  if (info) {
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
    info << dur << std::endl;

    info.seekg(0);  

    int number;
    int sum = 0;
    int count = 0;

    while (info >> number) {
      sum += number;
      count++;
    }

    double average = 0;
    if (count > 0) {
      average = static_cast<double>(sum) / count;
    }

    std::cout << "Average: " << average << std::endl;
  } else {
    std::cout << "file is not opened" << std::endl;
  }
  return 0;
}
