// g++ -std=c++20 average_levels_binary_tree.cpp -o albt
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

    void bfs_recursive(TreeNode* node) {
      std::cout << "bfs(): current node is " << node->val << std::endl;
      if (node->left != NULL) {
        bfs_recursive(node->left);
      }
      if (node->right != NULL) {
        bfs_recursive(node->right);
      }
      return;
    }

    std::vector<double>bfs_iterative(TreeNode* root) {
      std::deque<TreeNode*> node_queue;
      node_queue.push_front(root);
      std::vector<double> solution;
      while(!node_queue.empty()) {
        int queue_length = node_queue.size();
        std::vector<int> level;
        for (int iter = 0; iter < queue_length; iter++) {
          TreeNode* node = node_queue.front();
          node_queue.pop_front();
          level.push_back(node->val);
          if (node->left != NULL) {
            node_queue.push_back(node->left);
          }
          if (node->right != NULL) {
            node_queue.push_back(node->right);
          }
        }
        double level_avg = 0;
        double level_total = 0;
        int level_size = level.size();
        for (int iter = 0; iter < level_size; iter++) {
          level_total += level[iter];
        }
        level_avg = level_total/level_size;
        solution.push_back(level_avg);
      }
      return solution;
    }

    std::vector<double> averageOfLevels(TreeNode* root) {
       bfs_recursive(root);
       std::vector<double> solution = bfs_iterative(root);
       return solution;
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
  std::vector<double> solution = sol.averageOfLevels(treeNode0);
  for (int iter = 0; iter < solution.size(); iter++) {
    std::cout << "level average is " << solution[iter] << std::endl;
  }

  delete treeNode0;
  delete treeNode1;
  delete treeNode2;
  delete treeNode3;
  delete treeNode4;
  return 0;
}
