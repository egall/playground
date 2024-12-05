// g++ -std=c++20 diameter_of_tree.cpp -o dot
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

    int dfs(TreeNode* node) {
      if (node == NULL) {
        return -1;
      }
      int left_diameter = dfs(node->left);
      int right_diameter = dfs(node->right);
      max_diameter_ = std::max(max_diameter_, 2 + left_diameter + right_diameter);
      return 1 + std::max(left_diameter, right_diameter);
    }

    int diameterOfBinaryTree(TreeNode* root) {
       dfs(root);
       return max_diameter_;
    }

private:
  int max_diameter_ = 0;
};

int main()
{
  TreeNode* treeNode0 = new TreeNode(1);
  TreeNode* treeNode1 = new TreeNode(2);
  TreeNode* treeNode2 = new TreeNode(3);
  TreeNode* treeNode3 = new TreeNode(4);
  TreeNode* treeNode4 = new TreeNode(5);

  treeNode0->left = treeNode1;
  treeNode0->right = treeNode2;

  treeNode1->left = treeNode3;
  treeNode1->right = treeNode4;

  Solution sol;
  std::cout << "maximum diameter is " << sol.diameterOfBinaryTree(treeNode0) << '\n';

  delete treeNode0;
  delete treeNode1;
  delete treeNode2;
  delete treeNode3;
  delete treeNode4;
  return 0;
}
