/*
 * @lc app=leetcode.cn id=814 lang=c
 *
 * [814] 得分最高的最小轮调
 *
 * https://leetcode-cn.com/problems/binary-tree-pruning/description/
 *
 * algorithms
 * Medium (66.63%)
 * Total Accepted:    1.8K
 * Total Submissions: 2.7K
 * Testcase Example:  '[1,null,0,0,1]'
 *
 * 给定二叉树根结点 root ，此外树的每个结点的值要么是 0，要么是 1。
 * 
 * 返回移除了所有不包含 1 的子树的原二叉树。
 * 
 * ( 节点 X 的子树为 X 本身，以及所有 X 的后代。)
 * 
 * 
 * 示例1:
 * 输入: [1,null,0,0,1]
 * 输出: [1,null,0,null,1]
 * ⁠
 * 解释: 
 * 只有红色节点满足条件“所有不包含 1 的子树”。
 * 右图为返回的答案。
 * 
 * 
 * 
 * 
 * 
 * 示例2:
 * 输入: [1,0,1,0,0,0,1]
 * 输出: [1,null,1,null,1]
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例3:
 * 输入: [1,1,0,1,1,0,1,0]
 * 输出: [1,1,0,1,1,null,1]
 * 
 * 
 * 
 * 
 * 
 * 说明: 
 * 
 * 
 * 给定的二叉树最多有 100 个节点。
 * 每个节点的值只会为 0 或 1 。
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
bool isNotContainOne(struct TreeNode* root)
{
    if (root == NULL) return true;
    return (root->val == 0 && isNotContainOne(root->left) && isNotContainOne(root->right));
}

void freeSubTree(struct TreeNode* root)
{
    if (root == NULL) return;
    freeSubTree(root->left);
    freeSubTree(root->right);
    free(root);
    root = NULL;
    return;
}

struct TreeNode* pruneTree(struct TreeNode* root) {
    if (isNotContainOne(root))
    {
        freeSubTree(root);
        return NULL;
    }
    
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    return root;
}
