/*
 * @lc app=leetcode.cn id=442 lang=c
 *
 * [442] 数组中重复的数据
 *
 * https://leetcode-cn.com/problems/find-all-duplicates-in-an-array/description/
 *
 * algorithms
 * Medium (59.10%)
 * Total Accepted:    3.1K
 * Total Submissions: 5.2K
 * Testcase Example:  '[4,3,2,7,8,2,3,1]'
 *
 * 给定一个整数数组 a，其中1 ≤ a[i] ≤ n （n为数组长度）, 其中有些元素出现两次而其他元素出现一次。
 * 
 * 找到所有出现两次的元素。
 * 
 * 你可以不用到任何额外空间并在O(n)时间复杂度内解决这个问题吗？
 * 
 * 示例：
 * 
 * 
 * 输入:
 * [4,3,2,7,8,2,3,1]
 * 
 * 输出:
 * [2,3]
 * 
 * 
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDuplicates(int* nums, int numsSize, int* returnSize) {
    if (nums == NULL || numsSize <= 0) return NULL;
    for (int i = 0; i < numsSize; i++)
    {
        nums[(nums[i] - 1) % numsSize] += numsSize;
    }
    
    int cnt = 0;
    for(int i = 0; i < numsSize; i++)
    {
        //printf("nums[%d] = %d\n", i, nums[i]);
        if (nums[i] > 2 * numsSize) cnt++;
    }
    
    int *res = (int *)malloc(sizeof(int) * cnt);
    int j = 0;
    for(int i = 0; i < numsSize; i++)
    {
        if (nums[i] > 2 * numsSize) {
            res[j++] = i + 1;
        }
    }
    
    *returnSize = cnt;
    return res;
    
}
