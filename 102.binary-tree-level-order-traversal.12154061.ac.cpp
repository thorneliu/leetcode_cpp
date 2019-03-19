/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层次遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (53.41%)
 * Total Accepted:    16.9K
 * Total Submissions: 31.6K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。
 * 
 * 例如:
 * 给定二叉树: [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其层次遍历结果：
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<TreeNode*> currentNodes;
        vector<TreeNode*> nextNodes;
        if (root) currentNodes.push_back(root);

        while (!currentNodes.empty())
        {
            ans.push_back({});
            nextNodes.clear();
            for (auto node : currentNodes)
            {
                ans.back().push_back(node->val);
                if (node->left) nextNodes.push_back(node->left);
                if (node->right) nextNodes.push_back(node->right);
            }
            currentNodes = nextNodes;
        }
        
        return ans;
    }
};
