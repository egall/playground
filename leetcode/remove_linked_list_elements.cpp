// g++ -std=c++20 remove_linked_list_elements.cpp -o rlle
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
    ListNode* removeElements(ListNode* head, int val) {
      ListNode dummy_node(-1, head);
      ListNode* current_ptr = head;
      ListNode* previous_ptr = &dummy_node;
      while (current_ptr != NULL) {
        ListNode* next_ptr = current_ptr->next;
        if (current_ptr->val == val) {
          std::cout << "Found element " << val << std::endl;
          previous_ptr->next = next_ptr;
        } else {
          previous_ptr = current_ptr;
        }
        current_ptr = current_ptr->next;
      }
      return dummy_node.next;   
    }
};

int main()
{
  ListNode* list_node0 = new ListNode(1);
  ListNode* list_node1 = new ListNode(2);
  ListNode* list_node2 = new ListNode(6);
  ListNode* list_node3 = new ListNode(3);
  ListNode* list_node4 = new ListNode(4);
  ListNode* list_node5 = new ListNode(5);
  ListNode* list_node6 = new ListNode(6);
  list_node0->next = list_node1;
  list_node1->next = list_node2;
  list_node2->next = list_node3;
  list_node3->next = list_node4;
  list_node4->next = list_node5;
  list_node5->next = list_node6;

  Solution sol;
  ListNode* result = sol.removeElements(list_node0, 1);

  while (result != NULL) {
    std::cout << "element: " << result->val << std::endl;
    result = result->next;
  }
 
  delete list_node0;
  delete list_node1;
  delete list_node2;
  delete list_node3;
  delete list_node4;
  delete list_node5;
  delete list_node6;
  return 0;
}

