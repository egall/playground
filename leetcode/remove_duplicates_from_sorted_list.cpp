// g++ -std=c++20 remove_duplicates_from_sorted_list.cpp -o rdfsll
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
    ListNode* deleteDuplicates(ListNode* head) {
      ListNode* current_ptr = head;
      while (current_ptr != NULL) {
        while((current_ptr->next != NULL) && (current_ptr->val == current_ptr->next->val)) {
          current_ptr->next = current_ptr->next->next;
        }
        current_ptr = current_ptr->next;
      }
      return head;
    }
};

int main()
{
  ListNode* list_node0 = new ListNode(1);
  ListNode* list_node1 = new ListNode(1);
  ListNode* list_node2 = new ListNode(2);
  ListNode* list_node3 = new ListNode(2);
  ListNode* list_node4 = new ListNode(3);
  ListNode* list_node5 = new ListNode(3);
  ListNode* list_node6 = new ListNode(4);
  list_node0->next = list_node1;
  list_node1->next = list_node2;
  list_node2->next = list_node3;
  list_node3->next = list_node4;
  list_node4->next = list_node5;
  list_node5->next = list_node6;

  Solution sol;
  ListNode* result = sol.deleteDuplicates(list_node0);

  while (result != NULL) {
    std::cout << "element: " << result->val << std::endl;
    result = result->next;
  }
 
  delete list_node0;
  delete list_node1;
  delete list_node2;
  delete list_node3;
  return 0;
}

