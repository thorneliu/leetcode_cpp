/*
 * @lc app=leetcode.cn id=889 lang=c
 *
 * [889] 亲密字符串
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (52.91%)
 * Total Accepted:    736
 * Total Submissions: 1.4K
 * Testcase Example:  '[1,2,4,5,3,6,7]\n[4,5,2,6,7,3,1]'
 *
 * 返回与给定的前序和后序遍历匹配的任何二叉树。
 * 
 * pre 和 post 遍历中的值是不同的正整数。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
 * 输出：[1,2,3,4,5,6,7]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= pre.length == post.length <= 30
 * pre[] 和 post[] 都是 1, 2, ..., pre.length 的排列
 * 每个输入保证至少有一个答案。如果有多个答案，可以返回其中一个。
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
    p->val = val;
    p->left = p->right = NULL;
    return p;
}

struct TreeNode* constructFromPrePost(int* pre, int preSize, int* post, int postSize) {
    if (!pre || !post || (preSize != postSize) || preSize <= 0) return NULL;
    if (pre[0] != post[postSize - 1]) return NULL;
    
    int rootVal = pre[0];
    struct TreeNode* root = newNode(rootVal);
    if (preSize >= 2)
    {
        int leftRootVal = pre[1];
        int idx = 0;
        for (; idx < postSize; idx++)
        {
            if (post[idx] == leftRootVal) break;
        }
        
        root->left = constructFromPrePost(pre+1, idx+1, post, idx+1);
        root->right = constructFromPrePost(pre+idx+2, preSize - idx - 2, post + idx + 1, preSize - idx - 2);
    }
    
    return root;
}
