/*
 * @lc app=leetcode.cn id=162 lang=c
 *
 * [162] 寻找峰值
 *
 * https://leetcode-cn.com/problems/find-peak-element/description/
 *
 * algorithms
 * Medium (39.16%)
 * Total Accepted:    6.6K
 * Total Submissions: 16.8K
 * Testcase Example:  '[1,2,3,1]'
 *
 * 峰值元素是指其值大于左右相邻值的元素。
 * 
 * 给定一个输入数组 nums，其中 nums[i] ≠ nums[i+1]，找到峰值元素并返回其索引。
 * 
 * 数组可能包含多个峰值，在这种情况下，返回任何一个峰值所在位置即可。
 * 
 * 你可以假设 nums[-1] = nums[n] = -∞。
 * 
 * 示例 1:
 * 
 * 输入: nums = [1,2,3,1]
 * 输出: 2
 * 解释: 3 是峰值元素，你的函数应该返回其索引 2。
 * 
 * 示例 2:
 * 
 * 输入: nums = [1,2,1,3,5,6,4]
 * 输出: 1 或 5 
 * 解释: 你的函数可以返回索引 1，其峰值元素为 2；
 * 或者返回索引 5， 其峰值元素为 6。
 * 
 * 
 * 说明:
 * 
 * 你的解法应该是 O(logN) 时间复杂度的。
 * 
 */
int max(int *A, int l, int r)
{
    int m = l + (r -l)/2;
    if (r > l + 1)
    {
        int a = max(A, l, m);
        int b = max(A, m, r);
        return A[a] > A[b] ? a : b;
    }
    else
    {
        return A[l] > A[r] ? l : r;
    }
}

int findPeakElement(int* nums, int numsSize) {
    return max(nums, 0, numsSize -1);   
}
