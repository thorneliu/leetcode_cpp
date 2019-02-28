/*
 * @lc app=leetcode.cn id=671 lang=c
 *
 * [671] 二叉树中第二小的节点
 *
 * https://leetcode-cn.com/problems/second-minimum-node-in-a-binary-tree/description/
 *
 * algorithms
 * Easy (45.44%)
 * Total Accepted:    2K
 * Total Submissions: 4.5K
 * Testcase Example:  '[2,2,5,null,null,5,7]'
 *
 * 给定一个非空特殊的二叉树，每个节点都是正数，并且每个节点的子节点数量只能为 2 或
 * 0。如果一个节点有两个子节点的话，那么这个节点的值不大于它的子节点的值。 
 * 
 * 给出这样的一个二叉树，你需要输出所有节点中的第二小的值。如果第二小的值不存在的话，输出 -1 。
 * 
 * 示例 1:
 * 
 * 
 * 输入: 
 * ⁠   2
 * ⁠  / \
 * ⁠ 2   5
 * ⁠    / \
 * ⁠   5   7
 * 
 * 输出: 5
 * 说明: 最小的值是 2 ，第二小的值是 5 。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: 
 * ⁠   2
 * ⁠  / \
 * ⁠ 2   2
 * 
 * 输出: -1
 * 说明: 最小的值是 2, 但是不存在第二小的值。
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

typedef struct {
    int min;
    int min2;
    int cnt;
}minValHolder;

void updateMinValHolder(minValHolder *pRes, int val)
{
    if(pRes->cnt == 0)
    {
        pRes->min = val;
        pRes->cnt = 1;
        return;
    }
    
    if(pRes->cnt == 1)
    {
        if (val == pRes->min) return;
        
        if (val < pRes->min)
        {
            pRes->min2 = pRes->min;
            pRes->min = val;
            pRes->cnt = 2;
        }
        else
        {
            pRes->min2 = val;
            pRes->cnt = 2;
        }
        return;
    }
    
    if (pRes->cnt == 2)
    {
        if (val >= pRes->min2 || val == pRes->min) return;
        if (val < pRes->min)
        {
            pRes->min2 = pRes->min;
            pRes->min = val;
            return;
        }
        
        if (val > pRes->min)
        {
            pRes->min2 = val;
            return;
        }
    }
}

void tranverseTree(minValHolder *pRes, struct TreeNode* root)
{
    if (root == NULL) return;
    int val = root->val;
    updateMinValHolder(pRes, val);
    
    tranverseTree(pRes, root->left);
    tranverseTree(pRes, root->right);
    return;
}

int findSecondMinimumValue(struct TreeNode* root) {
    minValHolder res;
    memset(&res, 0, sizeof(res));
    minValHolder* pRes = &res;
    
    tranverseTree(pRes, root);
    return pRes->cnt == 2 ? pRes->min2 : -1;
}
