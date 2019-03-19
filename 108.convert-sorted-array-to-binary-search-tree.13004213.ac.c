/*
 * @lc app=leetcode.cn id=108 lang=c
 *
 * [108] 将有序数组转换为二叉搜索树
 *
 * https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (60.63%)
 * Total Accepted:    12.9K
 * Total Submissions: 21.2K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * 将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
 * 
 * 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
 * 
 * 示例:
 * 
 * 给定有序数组: [-10,-3,0,5,9],
 * 
 * 一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
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

struct TreeNode* newNode(int val)
{
    struct TreeNode* p = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    p->left = p->right = NULL;
    p->val = val;
    return p;
}

struct TreeNode* insert(struct TreeNode* root, int val)
{
    if (root == NULL)
    {
        struct TreeNode* p = newNode(val);
        return p;
    }
    
    int rootVal = root->val;
    if (val < rootVal)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
    
    return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if (nums == NULL || numsSize <= 0) return NULL;
    int mid = numsSize/2;
    //int i = mid - 1;
    //int j = numsSize - 1;
    struct TreeNode* root = newNode(nums[mid]);
    root->left = sortedArrayToBST(nums, mid);
    root->right = sortedArrayToBST(nums + mid + 1, numsSize - mid - 1);
    /*
    while(i >= 0 || j > mid)
    {
        if (i >= 0)  root = insert(root, nums[i--]);
        if (j > mid) root = insert(root, nums[j--]);
    }
    */
    
    return root;
}


