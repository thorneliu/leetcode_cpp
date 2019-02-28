/*
 * @lc app=leetcode.cn id=654 lang=c
 *
 * [654] 最大二叉树
 *
 * https://leetcode-cn.com/problems/maximum-binary-tree/description/
 *
 * algorithms
 * Medium (72.03%)
 * Total Accepted:    2.6K
 * Total Submissions: 3.7K
 * Testcase Example:  '[3,2,1,6,0,5]'
 *
 * 给定一个不含重复元素的整数数组。一个以此数组构建的最大二叉树定义如下：
 * 
 * 
 * 二叉树的根是数组中的最大元素。
 * 左子树是通过数组中最大值左边部分构造出的最大二叉树。
 * 右子树是通过数组中最大值右边部分构造出的最大二叉树。
 * 
 * 
 * 通过给定的数组构建最大二叉树，并且输出这个树的根节点。
 * 
 * Example 1:
 * 
 * 
 * 输入: [3,2,1,6,0,5]
 * 输入: 返回下面这棵树的根节点：
 * 
 * ⁠     6
 * ⁠   /   \
 * ⁠  3     5
 * ⁠   \    / 
 * ⁠    2  0   
 * ⁠      \
 * ⁠       1
 * 
 * 
 * 注意:
 * 
 * 
 * 给定的数组的大小在 [1, 1000] 之间。
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

// get the maxium index in Array *A, startindex l, endindex r
int max(int *A, int l, int r)
{
    int m = l + (r -l)/2;
    if (r > l + 1)
    {
        int a = max(A, l, m);
        int b = max(A, m, r);
        return A[a] > A[b] ? a : b;
    }
    else
    {
        return A[l] > A[r] ? l : r;
    }
}

struct TreeNode* newTreeNode(int val)
{
    struct TreeNode* p = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    p->val = val;
    p->left = p->right = NULL;
    return p;
}

struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize) {
    int peakIndex = max(nums, 0, numsSize - 1);
    struct TreeNode* root = newTreeNode(nums[peakIndex]);
    if (peakIndex > 0)
    {
        // something in the left
        root->left = constructMaximumBinaryTree(nums, peakIndex);
    }
    
    if (peakIndex < numsSize - 1)
    {
        root->right = constructMaximumBinaryTree(nums + peakIndex + 1, numsSize - peakIndex - 1);
    }
    
    return root;
}
