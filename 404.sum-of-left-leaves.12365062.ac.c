/*
 * @lc app=leetcode.cn id=404 lang=c
 *
 * [404] 左叶子之和
 *
 * https://leetcode-cn.com/problems/sum-of-left-leaves/description/
 *
 * algorithms
 * Easy (48.55%)
 * Total Accepted:    4.5K
 * Total Submissions: 9.2K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 计算给定二叉树的所有左叶子之和。
 * 
 * 示例：
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
 * 
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool hasleftLeaf(struct TreeNode* root)
{
    return root && root->left && !root->left->left && !root->left->right;
}

int sumOfLeftLeaves(struct TreeNode* root) {
    if (root == NULL) return 0;
    int sum = 0;
    if (hasleftLeaf(root))
    {
        sum += root->left->val;
    }
    
    return sum + sumOfLeftLeaves(root->right) + sumOfLeftLeaves(root->left);
}
