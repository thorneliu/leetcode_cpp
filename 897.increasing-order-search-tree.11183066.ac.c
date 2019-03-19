/*
 * @lc app=leetcode.cn id=897 lang=c
 *
 * [897] 回文素数
 *
 * https://leetcode-cn.com/problems/increasing-order-search-tree/description/
 *
 * algorithms
 * Easy (50.69%)
 * Total Accepted:    1.7K
 * Total Submissions: 3.3K
 * Testcase Example:  '[5,3,6,2,4,null,8,1,null,null,null,7,9]'
 *
 * 给定一个树，按中序遍历重新排列树，使树中最左边的结点现在是树的根，并且每个结点没有左子结点，只有一个右子结点。
 * 
 * 
 * 
 * 示例 ：
 * 
 * 输入：[5,3,6,2,4,null,8,1,null,null,null,7,9]
 * 
 * ⁠      5
 * ⁠     / \
 * ⁠   3    6
 * ⁠  / \    \
 * ⁠ 2   4    8
 * /        / \ 
 * 1        7   9
 * 
 * 输出：[1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
 * 
 * ⁠1
 * \
 * 2
 * \
 * 3
 * \
 * 4
 * \
 * 5
 * \
 * 6
 * \
 * 7
 * \
 * 8
 * \
 * ⁠                9  
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 给定树中的结点数介于 1 和 100 之间。
 * 每个结点都有一个从 0 到 1000 范围内的唯一整数值。
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

typedef struct TreeNode node;

void inOrderTranveseBST(struct TreeNode* root, struct TreeNode** curRes)
{
    if(root == NULL) return;
    inOrderTranveseBST(root->left, curRes);
    (*curRes)->right = root;
    (*curRes)->left = NULL;
    *curRes = root;
    inOrderTranveseBST(root->right, curRes);
    (*curRes)->left = (*curRes)->right = NULL;
}

struct TreeNode* increasingBST(struct TreeNode* root) {
    node node;
    struct TreeNode* pNode = &node;
    struct TreeNode** ppNode = &pNode;
    inOrderTranveseBST(root, ppNode);
    
    return node.right;
}
