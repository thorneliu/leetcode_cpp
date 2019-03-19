/*
 * @lc app=leetcode.cn id=145 lang=c
 *
 * [145] 二叉树的后序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Hard (63.69%)
 * Total Accepted:    10.5K
 * Total Submissions: 16.5K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 后序 遍历。
 * 
 * 示例:
 * 
 * 输入: [1,null,2,3]  
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3 
 * 
 * 输出: [3,2,1]
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
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
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void getNodeCnt(struct TreeNode* root, int* pCnt)
{
    if (root == NULL) return 0;
    *pCnt = *pCnt + 1;
    if (root->left)  getNodeCnt(root->left, pCnt);
    if (root->right) getNodeCnt(root->right, pCnt);
    
    return;
}

void dfs(struct TreeNode* root, int* pidx, int* array)
{
    if (root == NULL) return;
    if (root->left) dfs(root->left, pidx, array);
    if (root->right) dfs(root->right, pidx, array);
    array[*pidx] = root->val;
    *pidx = *pidx + 1;
    return;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int cnt = 0;
    getNodeCnt(root, &cnt);
    
    *returnSize = cnt;
    if (cnt == 0) return NULL;
    
    int* res = (int *)malloc(sizeof(int) * cnt);
    memset(res, 0, sizeof(int) * cnt);
    
    int idx = 0;
    dfs(root, &idx, res);
    return res;
}
