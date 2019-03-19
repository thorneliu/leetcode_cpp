/*
 * @lc app=leetcode.cn id=110 lang=c
 *
 * [110] 平衡二叉树
 *
 * https://leetcode-cn.com/problems/balanced-binary-tree/description/
 *
 * algorithms
 * Easy (46.25%)
 * Total Accepted:    10.5K
 * Total Submissions: 22.7K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，判断它是否是高度平衡的二叉树。
 * 
 * 本题中，一棵高度平衡二叉树定义为：
 * 
 * 
 * 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
 * 
 * 
 * 示例 1:
 * 
 * 给定二叉树 [3,9,20,null,null,15,7]
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回 true 。
 * 
 * 示例 2:
 * 
 * 给定二叉树 [1,2,2,3,3,null,null,4,4]
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   2
 * ⁠   / \
 * ⁠  3   3
 * ⁠ / \
 * ⁠4   4
 * 
 * 
 * 返回 false 。
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

#define MAX(x, y) ((x) > (y) ? (x) : (y))

int height(struct TreeNode* root, bool* isblance)
{
    if (root == NULL) return 0;
    int leftHeight = height(root->left, isblance);
    int rightHeight = height(root->right, isblance);
    if (((leftHeight + 1) < rightHeight ||
         (rightHeight + 1) < leftHeight)) 
    {
        *isblance = false;
    }
    return (1 + MAX(leftHeight, rightHeight));
}


bool isBalanced(struct TreeNode* root) {
    bool isblance = true;
    height(root, &isblance);
    return isblance;
}
