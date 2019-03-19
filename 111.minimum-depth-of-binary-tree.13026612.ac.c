/*
 * @lc app=leetcode.cn id=111 lang=c
 *
 * [111] 二叉树的最小深度
 *
 * https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (37.02%)
 * Total Accepted:    11.1K
 * Total Submissions: 30.1K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最小深度。
 * 
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回它的最小深度  2.
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
void dfs(struct TreeNode* root, int depth, int* minDepth)
{
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL) 
    {
        if (depth < *minDepth) *minDepth = depth;
        return;
    }

    dfs(root->left, depth + 1, minDepth);
    dfs(root->right, depth + 1, minDepth);    
    return;
}

int minDepth(struct TreeNode* root) {
    if (!root) return 0;
    
    int minDepth = INT_MAX;
    dfs(root, 1, &minDepth);
    
    return minDepth;
}
