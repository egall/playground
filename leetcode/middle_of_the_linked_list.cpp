// g++ -std=c++20 middle_of_the_linked_list.cpp -o mll 
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
    ListNode* middleNode(ListNode* head) {
       ListNode* fast_ptr = head;
       ListNode* slow_ptr = head;
       while (fast_ptr->next != NULL && fast_ptr->next->next != NULL) {
         fast_ptr = fast_ptr->next->next;
         slow_ptr = slow_ptr->next;
       }
       // handle last case
       if (fast_ptr->next != NULL) {
         slow_ptr = slow_ptr->next;
       }
       return slow_ptr;
    }
};

int main()
{
  ListNode* list_node0 = new ListNode(1);
  ListNode* list_node1 = new ListNode(2);
  ListNode* list_node2 = new ListNode(3);
  ListNode* list_node3 = new ListNode(4);
  list_node0->next = list_node1;
  list_node1->next = list_node2;
  list_node2->next = list_node3;

  Solution sol;
  ListNode* result = sol.middleNode(list_node0);

  while (result != NULL) {
    std::cout << "List node val is " << result->val << std::endl;
    result = result->next;
  }
 
  delete list_node0;
  delete list_node1;
  delete list_node2;
  delete list_node3;
  return 0;
}

