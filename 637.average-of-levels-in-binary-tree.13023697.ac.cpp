/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
 *
 * https://leetcode-cn.com/problems/average-of-levels-in-binary-tree/description/
 *
 * algorithms
 * Easy (56.61%)
 * Total Accepted:    3.9K
 * Total Submissions: 6.8K
 * Testcase Example:  '[3,9,20,15,7]'
 *
 * 给定一个非空二叉树, 返回一个由每层节点平均值组成的数组.
 * 
 * 示例 1:
 * 
 * 输入:
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 输出: [3, 14.5, 11]
 * 解释:
 * 第0层的平均值是 3,  第1层是 14.5, 第2层是 11. 因此返回 [3, 14.5, 11].
 * 
 * 
 * 注意：
 * 
 * 
 * 节点值的范围在32位有符号整数范围内。
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        vector<TreeNode*> current;
        vector<TreeNode*> next;
        
        if (root) current.push_back(root);
        
        while(!current.empty())
        {
            double sum = 0;
            double cnt = 0;
            for (auto& node : current)
            {
                sum += node->val;
                cnt++;
                if (node->left) next.push_back(node->left);
                if (node->right) next.push_back(node->right);
            }
            
            ans.push_back(sum/cnt);
            swap(current, next);
            next.clear();
        }
        
        return ans;
    }
};
