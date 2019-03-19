/*
 * @lc app=leetcode.cn id=530 lang=c
 *
 * [530] 二叉搜索树的最小绝对差
 *
 * https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/description/
 *
 * algorithms
 * Easy (51.49%)
 * Total Accepted:    2.6K
 * Total Submissions: 5.1K
 * Testcase Example:  '[1,null,3,2]'
 *
 * 给定一个所有节点为非负值的二叉搜索树，求树中任意两节点的差的绝对值的最小值。
 * 
 * 示例 :
 * 
 * 
 * 输入:
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    3
 * ⁠   /
 * ⁠  2
 * 
 * 输出:
 * 1
 * 
 * 解释:
 * 最小绝对差为1，其中 2 和 1 的差的绝对值为 1（或者 2 和 3）。
 * 
 * 
 * 注意: 树中至少有2个节点。
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
int min(int x, int y)
{
    return x < y ? x : y;
}

void dfs(struct TreeNode* root, int* pre, int* ans)
{
    if(root)
    {
        dfs(root->left, pre, ans);
        int diff = abs(*pre - root->val);
        *ans = min(*ans, diff);
        *pre = root->val;
        dfs(root->right, pre, ans);
    }
    
    return;
}


int getMinimumDifference(struct TreeNode* root) {
    int pre = INT_MAX;
    int ans = INT_MAX;
    dfs(root, &pre, &ans);
    
    return ans;
}
