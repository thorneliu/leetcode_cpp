/*
 * @lc app=leetcode.cn id=540 lang=c
 *
 * [540] 有序数组中的单一元素
 *
 * https://leetcode-cn.com/problems/single-element-in-a-sorted-array/description/
 *
 * algorithms
 * Medium (59.98%)
 * Total Accepted:    1.7K
 * Total Submissions: 2.8K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个只包含整数的有序数组，每个元素都会出现两次，唯有一个数只会出现一次，找出这个数。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [1,1,2,3,3,4,4,8,8]
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [3,3,7,7,10,11,11]
 * 输出: 10
 * 
 * 
 * 注意: 您的方案应该在 O(log n)时间复杂度和 O(1)空间复杂度中运行。
 * 
 */
int singleNonDuplicate(int* nums, int numsSize) {
    int l = 0;
    int r = numsSize;
    int m = 0;
    while(l < r)
    {
        m = l + (r -l)/2;
        // int n = (m % 2 == 0)? (m+1) : (m-1)
        int n = m ^ 1;
        if (nums[m] == nums[n])
        {
            l = m + 1;
        }
        else
        {
            r = m;
        }
    }
    
    return nums[l];
}
