/*
 * @lc app=leetcode.cn id=783 lang=cpp
 *
 * [783] 二叉搜索树中的搜索
 *
 * https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/description/
 *
 * algorithms
 * Easy (51.15%)
 * Total Accepted:    1.9K
 * Total Submissions: 3.6K
 * Testcase Example:  '[4,2,6,1,3,null,null]'
 *
 * 给定一个二叉搜索树的根结点 root, 返回树中任意两节点的差的最小值。
 * 
 * 示例：
 * 
 * 
 * 输入: root = [4,2,6,1,3,null,null]
 * 输出: 1
 * 解释:
 * 注意，root是树结点对象(TreeNode object)，而不是数组。
 * 
 * 给定的树 [4,2,6,1,3,null,null] 可表示为下图:
 * 
 * ⁠         4
 * ⁠       /   \
 * ⁠     2      6
 * ⁠    / \    
 * ⁠   1   3  
 * 
 * 最小的差值是 1, 它是节点1和节点2的差值, 也是节点3和节点2的差值。
 * 
 * 注意：
 * 
 * 
 * 二叉树的大小范围在 2 到 100。
 * 二叉树总是有效的，每个节点的值都是整数，且不重复。
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        int ans = INT_MAX;
        int len = valList_.size();
        for (int i = 1; i < len; i++)
        {
            auto diff = abs(valList_[i] - valList_[i-1]);
            ans = min(ans, diff);
        }
        
        return ans;
    }
private:
    vector<int> valList_;
    void inorder(TreeNode* root)
    {
        if (!root) return;
        inorder(root->left);
        valList_.push_back(root->val);
        inorder(root->right);
    }
};
