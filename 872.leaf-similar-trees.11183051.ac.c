/*
 * @lc app=leetcode.cn id=872 lang=c
 *
 * [872] 将数组拆分成斐波那契序列
 *
 * https://leetcode-cn.com/problems/leaf-similar-trees/description/
 *
 * algorithms
 * Easy (56.61%)
 * Total Accepted:    2.8K
 * Total Submissions: 5K
 * Testcase Example:  '[3,5,1,6,2,9,8,null,null,7,4]\n[3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]'
 *
 * 请考虑一颗二叉树上所有的叶子，这些叶子的值按从左到右的顺序排列形成一个 叶值序列 。
 * 
 * 
 * 
 * 举个例子，如上图所示，给定一颗叶值序列为 (6, 7, 4, 9, 8) 的树。
 * 
 * 如果有两颗二叉树的叶值序列是相同，那么我们就认为它们是 叶相似 的。
 * 
 * 如果给定的两个头结点分别为 root1 和 root2 的树是叶相似的，则返回 true；否则返回 false 。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 给定的两颗树可能会有 1 到 100 个结点。
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
//we have to define a vector-like stack in C
typedef struct {
    int data[100];
    int top;
}stack;

void getleafNodes(struct TreeNode* root, stack* pStack)
{
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL)
    {
        pStack->top++;
        pStack->data[pStack->top] = root->val;
    }
    
    getleafNodes(root->left, pStack);
    getleafNodes(root->right, pStack);
}

bool isSameStack(stack* ps1, stack* ps2)
{
    if (ps1->top != ps2->top) return false;
    int length = ps1->top;
    if(length == -1) return true;
    
    for (int i = 0; i <= length; i++)
    {
        if(ps1->data[i] != ps2->data[i]) return false;
    }
    
    return true;
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
    stack s1, s2;
    s1.top = -1;
    s2.top = -1;
    
    getleafNodes(root1, &s1);
    getleafNodes(root2, &s2);
    
    return isSameStack(&s1, &s2);
}
