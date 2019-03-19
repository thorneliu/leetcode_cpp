/*
 * @lc app=leetcode.cn id=169 lang=c
 *
 * [169] 求众数
 *
 * https://leetcode-cn.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (57.09%)
 * Total Accepted:    21.1K
 * Total Submissions: 36.9K
 * Testcase Example:  '[3,2,3]'
 *
 * 给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
 * 
 * 你可以假设数组是非空的，并且给定的数组总是存在众数。
 * 
 * 示例 1:
 * 
 * 输入: [3,2,3]
 * 输出: 3
 * 
 * 示例 2:
 * 
 * 输入: [2,2,1,1,1,2,2]
 * 输出: 2
 * 
 * 
 */
int getBit(int *nums, int numsSize, int BitPos)
{
    int i = 0;
    int n = 0;
    
    for(; i < numsSize; i++)
    {
        if (nums[i] >> BitPos & 0x1)
            n++;
    }
    
    if (n >= (numsSize/2 +1)) return 1;
    else return 0;
}

int majorityElement(int* nums, int numsSize) {
    int bitSet[32] = {0};
    
    int i = 0;
    for(; i < 32; i++)
    {
        bitSet[i] = getBit(nums, numsSize, i);
    }
    
    int result = 0;
    int power = 1;
    for(i = 0; i < 32; i++)
    {
        result = result + bitSet[i] * power;
        power = power * 2;
    }
    
    return result;
}
