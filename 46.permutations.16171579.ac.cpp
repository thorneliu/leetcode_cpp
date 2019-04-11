/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (67.68%)
 * Total Accepted:    20.5K
 * Total Submissions: 30.3K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个没有重复数字的序列，返回其所有可能的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 */
/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (67.40%)
 * Total Accepted:    19.4K
 * Total Submissions: 28.7K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个没有重复数字的序列，返回其所有可能的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 */
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur_;
        dfs(cur_, nums);

        return res_;
    }

private:
    vector<vector<int>> res_;

    void dfs(vector<int>& cur_, vector<int> notused_)
    {
        if (notused_.empty())
        {
            res_.push_back(cur_);
            return;
        }

        for (auto ele : notused_)
        {
            cur_.push_back(ele);
            dfs(cur_, getUpdatedNotUsed(notused_, ele));
            cur_.pop_back();
        }
    }

    vector<int> getUpdatedNotUsed(vector<int>& notused_, int ele)
    {
        vector<int> res;
        for (auto num : notused_)
        {
            if (num != ele) res.push_back(num);
        }

        return res;
    }
};


