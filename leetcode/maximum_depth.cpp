// g++ -std=c++20 maximum_depth.cpp -o md
#include <iostream>
#include <vector>
#include <set>
#include <deque>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    int maxDepth(TreeNode* root) {
      if (root == NULL) return 0;
      std::deque<TreeNode*> node_queue;
      node_queue.push_front(root);
      int tree_depth = 1;
      while (!node_queue.empty()) {
        int queue_length = node_queue.size();
        for (int iter = 0; iter < queue_length; iter++) {
          TreeNode* current_node = node_queue.front();
          if (current_node->left != NULL) {
            node_queue.push_back(current_node->left);
          }
          if (current_node->right != NULL) {
            node_queue.push_back(current_node->right);
          }
          node_queue.pop_front();
        }
        if (!(node_queue.empty())) {
          tree_depth++;
        }
      }
      return tree_depth;
    }
};

int main()
{
  TreeNode* treeNode0 = new TreeNode(3);
  TreeNode* treeNode1 = new TreeNode(9);
  TreeNode* treeNode2 = new TreeNode(20);
  TreeNode* treeNode3 = new TreeNode(15);
  TreeNode* treeNode4 = new TreeNode(7);

  treeNode0->left = treeNode1;
  treeNode0->right = treeNode2;

  treeNode2->left = treeNode3;
  treeNode2->right = treeNode4;

  Solution sol;
  std::cout << "maximum depth is " << sol.maxDepth(treeNode0) << '\n';

  delete treeNode0;
  delete treeNode1;
  delete treeNode2;
  delete treeNode3;
  delete treeNode4;
  return 0;
}
