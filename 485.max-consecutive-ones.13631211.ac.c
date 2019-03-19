/*
 * @lc app=leetcode.cn id=485 lang=c
 *
 * [485] 最大连续1的个数
 *
 * https://leetcode-cn.com/problems/max-consecutive-ones/description/
 *
 * algorithms
 * Easy (52.04%)
 * Total Accepted:    8.6K
 * Total Submissions: 16.4K
 * Testcase Example:  '[1,0,1,1,0,1]'
 *
 * 给定一个二进制数组， 计算其中最大连续1的个数。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [1,1,0,1,1,1]
 * 输出: 3
 * 解释: 开头的两位和最后的三位都是连续1，所以最大连续1的个数是 3.
 * 
 * 
 * 注意：
 * 
 * 
 * 输入的数组只包含 0 和1。
 * 输入数组的长度是正整数，且不超过 10,000。
 * 
 * 
 */
int findMaxConsecutiveOnes(int* nums, int numsSize) {
    if (nums == NULL || numsSize <= 0) return 0;
    
    int ans = 0,  cnt = 0;
    bool flag = false;
    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == 1)
        {
            cnt++;
            flag = true;
        }
        else if(flag)
        {
            flag = false;
            if (cnt > ans) ans = cnt;
            cnt = 0;
        }
    }
    
    if (flag && cnt > ans) ans = cnt;
    return ans;
}
