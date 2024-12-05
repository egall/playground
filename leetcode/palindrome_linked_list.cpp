// g++ -std=c++20 palindrome_linked_list.cpp -o pll
#include <iostream>
#include <set>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
       ListNode* slow = head;
       ListNode* fast = head;
       while (fast != nullptr && fast->next != nullptr) {
         fast = fast->next->next;
         slow = slow->next;
       }

       ListNode* previous_ptr = nullptr;
       ListNode* current_ptr = slow;
       while (current_ptr != nullptr) {
         ListNode* temp_ptr = current_ptr->next;
         current_ptr->next = previous_ptr;
         previous_ptr = current_ptr;
         current_ptr = temp_ptr;
       }

       ListNode* left_ptr = head;
       ListNode* right_ptr = previous_ptr;
       while (right_ptr != NULL) {
         if (left_ptr->val != right_ptr->val) {
           return false;
         }
         left_ptr = left_ptr->next;
         right_ptr = right_ptr->next;
       }
       return true;
    }
};

int main()
{
  ListNode* list_node0 = new ListNode(1);
  ListNode* list_node1 = new ListNode(2);
  ListNode* list_node2 = new ListNode(3);
  ListNode* list_node3 = new ListNode(4);
  ListNode* list_node4 = new ListNode(3);
  ListNode* list_node5 = new ListNode(2);
  ListNode* list_node6 = new ListNode(1);
  list_node0->next = list_node1;
  list_node1->next = list_node2;
  list_node2->next = list_node3;
  list_node3->next = list_node4;
  list_node4->next = list_node5;
  list_node5->next = list_node6;

  Solution sol;
  bool result = sol.isPalindrome(list_node0);

  std::cout << "Is list palendrome: " << result << std::endl;
 
  delete list_node0;
  delete list_node1;
  delete list_node2;
  delete list_node3;
  return 0;
}

