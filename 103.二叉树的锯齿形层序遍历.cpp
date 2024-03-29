#include "header.h"
/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (57.11%)
 * Likes:    437
 * Dislikes: 0
 * Total Accepted:    133.7K
 * Total Submissions: 234.2K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值的锯齿形层序遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
 * 
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回锯齿形层序遍历如下：
 * 
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
 * ⁠ [15,7]
 * ]
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
      public:

	vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
		vector<vector<int>> answer;
		deque<TreeNode *> q;
		bool right = true;
		if (!root) {
			return answer;
		}
		q.push_back(root);
		while(!q.empty()) {
			vector<TreeNode *> layer;
			vector<int> layernum;
			int size = q.size();
			for (int i = 0; i < size; i++) {
				TreeNode *node;
				if (right) {
					node = q.front();
					q.pop_front();
					if(node->left)
						q.push_back(node->left);
					if (node->right)
						q.push_back(node->right);
				}
				else {
					node = q.back();
					q.pop_back();
					if (node->right)
						q.push_front(node->right);
					if (node->left)
						q.push_front(node->left);
				}
				if (node) {
					layernum.push_back(node->val);
				}
			}
			right = !right;
			answer.push_back(layernum);
		}
		return answer;
	}
};
// @lc code=end
