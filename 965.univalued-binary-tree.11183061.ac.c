/*
 * @lc app=leetcode.cn id=965 lang=c
 *
 * [965] 独特的电子邮件地址
 *
 * https://leetcode-cn.com/problems/univalued-binary-tree/description/
 *
 * algorithms
 * Easy (65.45%)
 * Total Accepted:    2.1K
 * Total Submissions: 3.2K
 * Testcase Example:  '[1,1,1,1,1,null,1]'
 *
 * 如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。
 * 
 * 只有给定的树是单值二叉树时，才返回 true；否则返回 false。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：[1,1,1,1,1,null,1]
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：[2,2,2,5,2]
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 给定树的节点数范围是 [1, 100]。
 * 每个节点的值都是整数，范围为 [0, 99] 。
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
bool isUnivalTree(struct TreeNode* root) {
    if (root == NULL) return true;
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }
    else
    {
        if (root->left == NULL)
        {
            return root->val == root->right->val 
                && isUnivalTree(root->right);
        }
        else if (root->right == NULL)
        {
            return root->val == root->left->val 
                && isUnivalTree(root->left) ;
        }
        
        return root->val == root->left->val 
            && root->val == root->right->val 
            && isUnivalTree(root->left)  
            && isUnivalTree(root->right) ;
    }
}
