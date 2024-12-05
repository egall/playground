// g++ -std=c++20 max_profit.cpp -o mp
#include <iostream>
#include <vector>
#include <set>


    int maxProfit(std::vector<int>& prices) {
      int max_profit = 0;
      int lowest_price_index = 0;
      for (int itor = 0; itor < prices.size(); itor++) {
        if (prices[lowest_price_index] < prices[itor]) {
          int current_profit = prices[itor] - prices[lowest_price_index];
          if (max_profit < current_profit) {
            max_profit = current_profit;
          }
        } else {
          lowest_price_index = itor;
        }
      }
      return max_profit;       
    }

int main()
{
  int result = 0;
  // Test 0
  std::vector<int> nums0 = {7,1,5,3,6,4};
  result = maxProfit(nums0);
  std::cout << "Test #0: max profit is " << result << std::endl;

  // Test 1
  std::vector<int> nums1 = {7,6,4,3,1};
  result = maxProfit(nums1);
  std::cout << "Test #1: max profit is " << result << std::endl;

  return 0;
}
