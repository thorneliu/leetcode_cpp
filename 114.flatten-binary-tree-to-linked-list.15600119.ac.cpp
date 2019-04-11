/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 *
 * https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (59.15%)
 * Total Accepted:    5.6K
 * Total Submissions: 9.5K
 * Testcase Example:  '[1,2,5,3,4,null,6]'
 *
 * 给定一个二叉树，原地将它展开为链表。
 * 
 * 例如，给定二叉树
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   5
 * ⁠/ \   \
 * 3   4   6
 * 
 * 将其展开为：
 * 
 * 1
 * ⁠\
 * ⁠ 2
 * ⁠  \
 * ⁠   3
 * ⁠    \
 * ⁠     4
 * ⁠      \
 * ⁠       5
 * ⁠        \
 * ⁠         6
 * 
 */
/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 *
 * https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (58.46%)
 * Total Accepted:    5.1K
 * Total Submissions: 8.8K
 * Testcase Example:  '[1,2,5,3,4,null,6]'
 *
 * 给定一个二叉树，原地将它展开为链表。
 * 
 * 例如，给定二叉树
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   5
 * ⁠/ \   \
 * 3   4   6
 * 
 * 将其展开为：
 * 
 * 1
 * ⁠\
 * ⁠ 2
 * ⁠  \
 * ⁠   3
 * ⁠    \
 * ⁠     4
 * ⁠      \
 * ⁠       5
 * ⁠        \
 * ⁠         6
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
    void flatten(TreeNode* root) {
        dfs(root);
    }

private:
    pair<TreeNode*, TreeNode*> dfs(TreeNode* root)
    {
        if (nullptr == root) return make_pair(nullptr, nullptr);
        if (nullptr == root->left && nullptr == root->right) return make_pair(root, root);

        if (nullptr == root->left)
        {
            auto pair = dfs(root->right);
            root->right = pair.first;
            return make_pair(root, pair.second);
        }

        if (nullptr == root->right)
        {
            auto pair = dfs(root->left);
            root->left = nullptr;
            root->right = pair.first;
            return make_pair(root, pair.second);
        }

        auto pair_left = dfs(root->left);
        auto pair_right = dfs(root->right);

        root->left = nullptr;
        root->right = pair_left.first;
        pair_left.second->right = pair_right.first;

        return make_pair(root, pair_right.second);

    }
};


