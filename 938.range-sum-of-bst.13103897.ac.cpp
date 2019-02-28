/*
 * @lc app=leetcode.cn id=938 lang=cpp
 *
 * [938] 最大为 N 的数字组合
 *
 * https://leetcode-cn.com/problems/range-sum-of-bst/description/
 *
 * algorithms
 * Medium (75.70%)
 * Total Accepted:    1.5K
 * Total Submissions: 1.9K
 * Testcase Example:  '[10,5,15,3,7,null,18]\n7\n15'
 *
 * 给定二叉搜索树的根结点 root，返回 L 和 R（含）之间的所有结点的值的和。
 * 
 * 二叉搜索树保证具有唯一的值。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：root = [10,5,15,3,7,null,18], L = 7, R = 15
 * 输出：32
 * 
 * 
 * 示例 2：
 * 
 * 输入：root = [10,5,15,3,7,13,18,1,null,6], L = 6, R = 10
 * 输出：23
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中的结点数量最多为 10000 个。
 * 最终的答案保证小于 2^31。
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
    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum = 0;
        if (!root) return sum;
        if (R < root->val)
        {
            return rangeSumBST(root->left, L, R);
        }
        
        if (L > root->val)
        {
            return rangeSumBST(root->right, L, R);
        }
        
        sum = root->val + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
        return sum;
    }
};
