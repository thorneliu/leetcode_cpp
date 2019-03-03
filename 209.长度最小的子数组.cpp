/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 *
 * https://leetcode-cn.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (36.90%)
 * Total Accepted:    6.4K
 * Total Submissions: 17.3K
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * 给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组。如果不存在符合条件的连续子数组，返回 0。
 * 
 * 示例: 
 * 
 * 输入: s = 7, nums = [2,3,1,2,4,3]
 * 输出: 2
 * 解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。
 * 
 * 
 * 进阶:
 * 
 * 如果你已经完成了O(n) 时间复杂度的解法, 请尝试 O(n log n) 时间复杂度的解法。
 * 
 */
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) return 0;
        auto size = nums.size();

        int sum = 0, ans = INT_MAX;
        int l = 0, r = 0;
        for (r = 0; r < size; r++)
        {
            sum += nums[r];

            if (sum >= s)
            {
                while(sum - nums[l] >= s && l <= r)
                {
                    sum -= nums[l++];
                }
                ans = min(ans, r - l + 1);
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};

