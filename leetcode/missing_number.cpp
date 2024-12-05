// g++ -std=c++20 missing_number.cpp -o mn
#include <iostream>
#include <set>
#include <vector>

int missingNumber(std::vector<int>& nums) {
  int result = nums.size();
  int array_length = result;
  for (int iter = 0; iter < array_length; iter++) {
    result += (iter - nums[iter]);
  }   
  return result;
}

int main()
{
  std::vector<int> nums = {3,0,1};
  std::cout << "missing number is " << missingNumber(nums) << std::endl;
  return 0;
}
