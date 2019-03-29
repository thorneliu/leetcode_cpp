/*
 * @lc app=leetcode.cn id=105 lang=c
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (55.80%)
 * Total Accepted:    8.5K
 * Total Submissions: 15.3K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 根据一棵树的前序遍历与中序遍历构造二叉树。
 * preorder = [3,9,20,15,7]
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 前序遍历 preorder = [3,9,20,15,7]
 * 中序遍历 inorder = [9,3,15,20,7]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
struct TreeNode* newNode(int val)
{
    struct TreeNode* p = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    p->val = val;
    p->left = p->right = NULL;
    return p;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    if (!preorder || !inorder || preorderSize != inorderSize || inorderSize <= 0) return NULL;
    
    int rootVal = preorder[0];
    struct TreeNode* root = newNode(rootVal);
	
	if (inorderSize == 1) return root;
    
    // find the root index in inorder list
    int idx = 0;
    for (; idx < inorderSize; idx ++)
    {
        if (inorder[idx] == rootVal) break;
    }
    
    root->left = buildTree(preorder + 1, idx, inorder, idx);
    root->right = buildTree(preorder + idx + 1,  inorderSize - idx -1, inorder + idx + 1, inorderSize - idx -1);
    return root;
}
