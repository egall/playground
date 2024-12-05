// g++ -std=c++20 same_tree.cpp -o st
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

    bool isSameTree(TreeNode* p, TreeNode* q) {
      if (p == NULL && q == NULL) {
        return true;
      }
      if (p == NULL || q == NULL) {
        return false;
      }
      if (p->val != q->val) {
        return false;
      }
      return (isSameTree(p->left, q->left) && (isSameTree(p->right, q->right)));
    }

};

int main()
{
  TreeNode* tree0Node0 = new TreeNode(3);
  TreeNode* tree0Node1 = new TreeNode(9);
  TreeNode* tree0Node2 = new TreeNode(20);
  TreeNode* tree0Node3 = new TreeNode(15);
  TreeNode* tree0Node4 = new TreeNode(8);

  tree0Node0->left = tree0Node1;
  tree0Node0->right = tree0Node2;

  tree0Node2->left = tree0Node3;
  tree0Node2->right = tree0Node4;

  TreeNode* tree1Node0 = new TreeNode(3);
  TreeNode* tree1Node1 = new TreeNode(9);
  TreeNode* tree1Node2 = new TreeNode(20);
  TreeNode* tree1Node3 = new TreeNode(15);
  TreeNode* tree1Node4 = new TreeNode(7);

  tree1Node0->left = tree1Node1;
  tree1Node0->right = tree1Node2;

  tree1Node2->left = tree1Node3;
  tree1Node2->right = tree1Node4;

  Solution sol;
  bool solution = sol.isSameTree(tree0Node0, tree1Node0);

  std::cout << "solution is " << std::to_string(solution) << std::endl;

  delete tree0Node0;
  delete tree0Node1;
  delete tree0Node2;
  delete tree0Node3;
  delete tree0Node4;

  delete tree1Node0;
  delete tree1Node1;
  delete tree1Node2;
  delete tree1Node3;
  delete tree1Node4;

  return 0;
}
