// g++ -std=c++20 contains_duplicates.cpp -o cd
#include <iostream>
#include <set>
#include <vector>
 
bool containsDuplicate(std::vector<int>& nums) {
  std::set<int> values_seen;
  for (auto& it : nums) {
    if (values_seen.contains(it)) {
      return true;
    }
    values_seen.insert(it);
  }
  return false;
}

int main()
{
  std::vector<int> nums = {1,1,1,3,3,4,3,2,4,2};
  if (containsDuplicate(nums)) {
    std::cout << "true" << std::endl;
  } else {
    std::cout << "false" << std::endl;
  }
  return 0;
}
