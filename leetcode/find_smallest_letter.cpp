// g++ -std=c++20 find_smallest_letter.cpp -o fsl
#include <iostream>
#include <vector>
#include <set>

class Solution {
public:
    char nextGreatestLetter(std::vector<char>& letters, char target) {
      int left = 0;
      int right = letters.size() - 1;
      if ( !((target < letters[left]) || (target >= letters[right])) ) {
        while (left <= right) {
          int current = (left + right)/2;
          if (target < letters[current]) {
            right = current - 1;
          } else {
            left = current + 1;
          }
        }
      }
      return letters[left];
    }
};

int main()
{
  Solution sol;
  std::vector<char> letters{'c','f','j'};

  char solution = sol.nextGreatestLetter(letters, 'a');

  std::cout << "Letter is " << solution << std::endl;

  std::vector<char> letters2{'x','x','y','y'};

  char solution2 = sol.nextGreatestLetter(letters2, 'z');

  std::cout << "Letter is " << solution2 << std::endl;
  return 0;
}
