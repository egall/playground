// g++ -std=c++20 linked_list_cycle.cpp -o llc
#include <iostream>
#include <set>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL) {
            return false;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
            if (fast->next == NULL) {
                return false;
            }
            fast = fast->next;
            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
};

int main()
{
  ListNode* list_node0 = new ListNode(3);
  ListNode* list_node1 = new ListNode(2);
  ListNode* list_node2 = new ListNode(0);
  ListNode* list_node3 = new ListNode(-4);
  list_node0->next = list_node1;
  list_node1->next = list_node2;
  list_node2->next = list_node3;

  ListNode* ptr = list_node0;
  while (ptr->next != NULL) {
    std::cout << "List node val is " << ptr->val << std::endl;
    ptr = ptr->next;
  }
 
  Solution sol;
  sol.hasCycle(list_node0);

  delete list_node0;
  delete list_node1;
  delete list_node2;
  delete list_node3;
  return 0;
}

