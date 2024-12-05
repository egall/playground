// g++ -std=c++20 merge_two_sorted_lists.cpp -o mtsl
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      ListNode dummy;
      ListNode* tail = &dummy;
      while (list1 != NULL && list2 != NULL) {
        if (list1->val < list2->val) {
          tail->next = list1;
          list1 = list1->next;
        } else {
          tail->next = list2;
          list2 = list2->next;
        }
        tail = tail->next;
      }

      if (list1 != NULL) {
        tail->next = list1;
      } else if (list2 != NULL) {
        tail->next = list2;
      }
      return dummy.next;
    }
};

int main()
{
  ListNode* list0_node0 = new ListNode(1);
  ListNode* list0_node1 = new ListNode(1);
  ListNode* list0_node2 = new ListNode(2);
  ListNode* list0_node3 = new ListNode(2);

  ListNode* list1_node0 = new ListNode(3);
  ListNode* list1_node1 = new ListNode(3);
  ListNode* list1_node2 = new ListNode(4);
  ListNode* list1_node3 = new ListNode(4);

  list0_node0->next = list0_node1;
  list0_node1->next = list0_node2;
  list0_node2->next = list0_node3;

  list1_node0->next = list1_node1;
  list1_node1->next = list1_node2;
  list1_node2->next = list1_node3;

  Solution sol;
  ListNode* result = sol.mergeTwoLists(list0_node0, list1_node0);

  while (result != NULL) {
    std::cout << "element: " << result->val << std::endl;
    result = result->next;
  }
 
  delete list0_node0;
  delete list0_node1;
  delete list0_node2;
  delete list0_node3;

  delete list1_node0;
  delete list1_node1;
  delete list1_node2;
  delete list1_node3;
  return 0;
}

