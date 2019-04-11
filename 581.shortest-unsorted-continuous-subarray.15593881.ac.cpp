/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 *
 * https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/description/
 *
 * algorithms
 * Easy (31.59%)
 * Total Accepted:    3.7K
 * Total Submissions: 11.6K
 * Testcase Example:  '[2,6,4,8,10,9,15]'
 *
 * 给定一个整数数组，你需要寻找一个连续的子数组，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。
 * 
 * 你找到的子数组应是最短的，请输出它的长度。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [2, 6, 4, 8, 10, 9, 15]
 * 输出: 5
 * 解释: 你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。
 * 
 * 
 * 说明 :
 * 
 * 
 * 输入的数组长度范围在 [1, 10,000]。
 * 输入的数组可能包含重复元素 ，所以升序的意思是<=。
 * 
 * 
 */
/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 *
 * https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/description/
 *
 * algorithms
 * Easy (31.11%)
 * Total Accepted:    3.4K
 * Total Submissions: 10.8K
 * Testcase Example:  '[2,6,4,8,10,9,15]'
 *
 * 给定一个整数数组，你需要寻找一个连续的子数组，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。
 * 
 * 你找到的子数组应是最短的，请输出它的长度。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [2, 6, 4, 8, 10, 9, 15]
 * 输出: 5
 * 解释: 你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。
 * 
 * 
 * 说明 :
 * 
 * 
 * 输入的数组长度范围在 [1, 10,000]。
 * 输入的数组可能包含重复元素 ，所以升序的意思是<=。
 * 
 * 
 */
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        // find the first index i from right to left which nums[i - 1] > nums[i]
        int size = nums.size();
        int i = size - 1;
        for (; i >= 1; i--)
        {
            if (nums[i - 1] > nums[i]) break;
        }

        // find the first index j from left to right which nums[i + 1] < nums[i]
        int j = 0;
        for (; j < size - 1; j++)
        {
            if (nums[j + 1] < nums[j]) break;
        }

        if (i <= j) return 0;
        
        // return i - j + 1;
        // we have to expand the interval because to include equal elements...
        int max = nums[i];
        int min = nums[j];
        for (int k = j; k <= i; k++)
        {
            if (nums[k] < min) min = nums[k];
            if (nums[k] > max) max = nums[k];
        }

        while(i + 1 < size && nums[i + 1] < max) i++;

        auto left = nums[j];
        while(j - 1 >= 0 && nums[j - 1] > min) j--;

        return i - j + 1; 
    }
};


