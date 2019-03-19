/*
 * @lc app=leetcode.cn id=594 lang=cpp
 *
 * [594] 最长和谐子序列
 *
 * https://leetcode-cn.com/problems/longest-harmonious-subsequence/description/
 *
 * algorithms
 * Easy (38.52%)
 * Total Accepted:    2K
 * Total Submissions: 5.2K
 * Testcase Example:  '[1,3,2,2,5,2,3,7]'
 *
 * 和谐数组是指一个数组里元素的最大值和最小值之间的差别正好是1。
 * 
 * 现在，给定一个整数数组，你需要在所有可能的子序列中找到最长的和谐子序列的长度。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [1,3,2,2,5,2,3,7]
 * 输出: 5
 * 原因: 最长的和谐数组是：[3,2,2,2,3].
 * 
 * 
 * 说明: 输入的数组长度最大不超过20,000.
 * 
 */
/*
 * @lc app=leetcode.cn id=594 lang=cpp
 *
 * [594] 最长和谐子序列
 *
 * https://leetcode-cn.com/problems/longest-harmonious-subsequence/description/
 *
 * algorithms
 * Easy (38.52%)
 * Total Accepted:    2K
 * Total Submissions: 5.2K
 * Testcase Example:  '[1,3,2,2,5,2,3,7]'
 *
 * 和谐数组是指一个数组里元素的最大值和最小值之间的差别正好是1。
 * 
 * 现在，给定一个整数数组，你需要在所有可能的子序列中找到最长的和谐子序列的长度。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [1,3,2,2,5,2,3,7]
 * 输出: 5
 * 原因: 最长的和谐数组是：[3,2,2,2,3].
 * 
 * 
 * 说明: 输入的数组长度最大不超过20,000.
 * 
 */
class Solution {
public:
    int findLHS(vector<int>& nums) {
        auto size = nums.size();
        if (size <= 1) return 0;

        sort(nums.begin(), nums.end());
        int curValueCnt = 1;
        int curValue = nums[0];
        int curValuePlus1 = __INT_MAX__;
        int curValuePlus1Cnt = 0;

        int ans = 0;
        for (int i = 1; i < size; i++)
        {
            if (nums[i] == curValue)
            {
                curValueCnt++;
            } else if (nums[i] == curValue + 1)
            {
                curValuePlus1 = nums[i];
                curValuePlus1Cnt++;
            }
            else
            {
                if (curValuePlus1Cnt > 0)
                {
                    ans = max(ans, (curValueCnt + curValuePlus1Cnt));
                    if (nums[i] == curValue + 2)
                    {
                        curValue = curValuePlus1;
                        curValueCnt = curValuePlus1Cnt;
                        curValuePlus1 = nums[i];
                        curValuePlus1Cnt = 1;
                    }
                    else
                    {
                        curValue = nums[i];
                        curValueCnt = 1;
                        curValuePlus1 = __INT_MAX__;
                        curValuePlus1Cnt = 0;
                    }
                    
                }
                else
                {
                    curValue = nums[i];
                    curValueCnt = 1;
                    curValuePlus1 = __INT_MAX__;
                    curValuePlus1Cnt = 0;
                }
            }
        }

        if (curValuePlus1Cnt > 0)
        {
            ans = max(ans, curValueCnt + curValuePlus1Cnt);
        }

        return ans;
    }
};

