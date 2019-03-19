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
void getNodeCnt(struct TreeNode* root, int* cnt)
{
    if(root) 
    {
        (*cnt)++;
        if(root->left) getNodeCnt(root->left, cnt);
        if(root->right) getNodeCnt(root->right, cnt);
    }
}

void getNodeVal(struct TreeNode* root, int* pindex, int* p)
{
    if (root)
    {
        p[*pindex] = root->val;
        (*pindex)++;
        if (root->left) getNodeVal(root->left, pindex, p);
        if (root->right) getNodeVal(root->right, pindex, p);
    }
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int cnt = 0;
    getNodeCnt(root, &cnt);
    
    *returnSize = cnt;
    int *p = (int *)malloc(sizeof(int) * cnt);
    memset(p, 0, sizeof(int) * cnt);
    int index = 0;
    getNodeVal(root, &index, p);
    
    return p;
}
