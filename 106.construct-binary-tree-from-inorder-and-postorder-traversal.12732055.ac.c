/*
 * @lc app=leetcode.cn id=106 lang=c
 *
 * [106] 从中序与后序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (58.06%)
 * Total Accepted:    5.2K
 * Total Submissions: 8.9K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * 根据一棵树的中序遍历与后序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 中序遍历 inorder = [9,3,15,20,7]
 * 后序遍历 postorder = [9,15,7,20,3]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
struct TreeNode* newNode(val)
{
    struct TreeNode* p = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    p->val = val;
    p->left = p->right = NULL;
    return p;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    if (inorder == NULL
        || postorder == NULL
        || (inorderSize != postorderSize) 
        || inorderSize <= 0
       ) return NULL;
    
    int rootVal = postorder[postorderSize - 1];
    struct TreeNode* root = newNode(rootVal);
    int idx = 0;
    for (; idx < inorderSize - 1; idx++)
    {
        if (inorder[idx] == rootVal) break;
    }
    root->left = buildTree(inorder, idx, postorder, idx);
    root->right = buildTree(inorder+idx+1, inorderSize-idx-1, postorder+idx, inorderSize-idx-1);
    return root;
}
