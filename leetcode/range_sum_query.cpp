// g++ -std=c++20 range_sum_query.cpp -o rsq
#include <iostream>
#include <set>
#include <vector>

class NumArray {
public:
    std::vector<int> precompute_sum_array;
    NumArray(std::vector<int>& nums) {
       int current_sum = 0;
       for (auto num : nums) {
         current_sum += num;
         precompute_sum_array.push_back(current_sum);
       }
    }
    
    int sumRange(int left, int right) {
       if (left == 0) {
         return precompute_sum_array[right];
       } else {
         return precompute_sum_array[right] - precompute_sum_array[left-1]; 
       }
    }
};

int main()
{
  std::vector<int> nums = {-2, 0, 3, -5, 2, -1};
  NumArray num_array(nums);
  std::cout << "missing number is " << num_array.sumRange(0,5) << std::endl;
  return 0;
}
