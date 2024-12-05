// g++ -std=c++20 path_sum.cpp -o ps
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

    bool dfs (TreeNode* node, int currentSum) {
      if (node == NULL) {
        return false;
      }
      currentSum += node->val;
      if ( (node->left == NULL) && (node->right == NULL) ) {
        return currentSum == targetSum_;
      }
      return (dfs(node->left, currentSum) || dfs(node->right, currentSum));
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
      targetSum_ = targetSum;
      return dfs(root, 0);
    }

private:
  int targetSum_;

};

int main()
{
  TreeNode* treeNode0 = new TreeNode(5);
  TreeNode* treeNode1 = new TreeNode(4);
  TreeNode* treeNode2 = new TreeNode(8);
  TreeNode* treeNode3 = new TreeNode(11);

  TreeNode* treeNode4 = new TreeNode(13);
  TreeNode* treeNode5 = new TreeNode(4);
  TreeNode* treeNode6 = new TreeNode(7);
  TreeNode* treeNode7 = new TreeNode(2);
  TreeNode* treeNode8 = new TreeNode(1);

  treeNode0->left = treeNode1;
  treeNode0->right = treeNode2;

  treeNode1->left = treeNode3;

  treeNode2->left = treeNode4;
  treeNode2->right = treeNode5;

  treeNode3->left = treeNode6;
  treeNode3->right = treeNode7;

  treeNode5->right = treeNode8;

  Solution sol;
  std::cout << "Has path sum: " << std::to_string(sol.hasPathSum(treeNode0, 22)) << '\n';

  delete treeNode0;
  delete treeNode1;
  delete treeNode2;
  delete treeNode3;
  delete treeNode4;
  return 0;
}
