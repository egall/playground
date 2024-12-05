// g++ -std=c++20 single_number.cpp -o sn
#include <iostream>
#include <vector>
#include <set>


int singleNumber(std::vector<int>& nums) {
   int result = 0;
   for (auto& num : nums) {
     result = result ^ num;
   }
   return result;       
}

int main()
{
  int result = 0;
  // Test 0
  std::vector<int> nums0 = {2,2,1};
  result = singleNumber(nums0);
  std::cout << "Test 0 single number is " << result << std::endl;

  // Test 1
  std::vector<int> nums1 = {4,1,2,1,2};
  result = singleNumber(nums1);
  std::cout << "Test 1 single number is " << result << std::endl;

  // Test 2
  std::vector<int> nums2 = {1};
  result = singleNumber(nums2);
  std::cout << "Test 2 single number is " << result << std::endl;

  return 0;
}
