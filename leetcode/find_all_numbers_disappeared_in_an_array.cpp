// g++ -std=c++20 find_all_numbers_disappeared_in_an_array.cpp -o fandiaa
#include <iostream>
#include <vector>
#include <set>


std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
   int n = nums.size();
   std::set<int> nums_set(nums.begin(), nums.end());
   std::vector<int> result;
   for (int iter = 1; iter < n+1; iter++) {
       if (!(nums_set.contains(iter))) {
         result.push_back(iter);
       }
   }
   return result;       
}

int main()
{
  std::vector<int> nums = {4,3,2,7,8,2,3,1};
  std::vector<int> result = findDisappearedNumbers(nums);
  std::cout << "disappeared numbers are: ";
  for (auto num : result) {
    std::cout << num << ' ';
  }
  std::cout << '\n';
  return 0;
}
