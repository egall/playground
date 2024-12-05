// g++ -std=c++20 counting_bits.cpp -o cb
#include <iostream>
#include <set>
#include <vector>

std::vector<int> countBits(int n) {
  std::vector<int> output_array(n+1);
  int offset = 1;
  for (int iter = 1; iter <= n+1; iter++) {
    if (offset*2 == iter) {
      offset = iter;
    }
    output_array[iter] = (1 + output_array[iter-offset]);
  }
  return output_array;
}


int main()
{
  int num = 2;
  std::vector<int> output_array = countBits(num);
  for (auto output : output_array) {
    std::cout << "output is " << output << std::endl;
  }
  return 0;
}
