// g++ -std=c++20 climbing_stairs.cpp -o cs
#include <iostream>
#include <vector>
#include <set>


int climbingStairs(int n) {
   int result = 0;
   int prev = 1;
   int trailer = 1;
   for (int iter = 0; iter < n; iter++) {
     result = prev;
     prev = trailer + prev;
     trailer = result;
   }
   return result;       
}

int main()
{
  int result = 0;
  // Test 0
  int num0 = 2;
  result = climbingStairs(num0);
  std::cout << "Test 0 climbing stairs is " << result << std::endl;

  // Test 1
  int num1 = 3;
  result = climbingStairs(num1);
  std::cout << "Test 1 climbing stairs is " << result << std::endl;

  // Test 2
  int num2 = 8;
  result = climbingStairs(num2);
  std::cout << "Test 2 climbing stairs is " << result << std::endl;

  return 0;
}
