/*
 * @lc app=leetcode.cn id=747 lang=c
 *
 * [747] 使用最小花费爬楼梯
 *
 * https://leetcode-cn.com/problems/largest-number-at-least-twice-of-others/description/
 *
 * algorithms
 * Easy (38.42%)
 * Total Accepted:    6K
 * Total Submissions: 15.7K
 * Testcase Example:  '[0,0,0,1]'
 *
 * 在一个给定的数组nums中，总是存在一个最大元素 。
 * 
 * 查找数组中的最大元素是否至少是数组中每个其他数字的两倍。
 * 
 * 如果是，则返回最大元素的索引，否则返回-1。
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums = [3, 6, 1, 0]
 * 输出: 1
 * 解释: 6是最大的整数, 对于数组中的其他整数,
 * 6大于数组中其他元素的两倍。6的索引是1, 所以我们返回1.
 * 
 * 
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: nums = [1, 2, 3, 4]
 * 输出: -1
 * 解释: 4没有超过3的两倍大, 所以我们返回 -1.
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * nums 的长度范围在[1, 50].
 * 每个 nums[i] 的整数范围在 [0, 99].
 * 
 * 
 */
int dominantIndex(int* nums, int numsSize) {
    if (nums == NULL || numsSize < 0) return -1;
    if (numsSize == 1) return 0;
    
    int m1 = nums[0];
    int m2 = 0;
    int index = 0;
    bool isM2Set = false;
    
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] > m1)
        {
            m2 = m1;
            isM2Set = true;
            m1 = nums[i];
            index = i;
        }
        else
        {
            if (!isM2Set)
            {
                m2 = nums[i];
                isM2Set = true;
            }
            else
            {
                if (m2 < nums[i])
                {
                    m2 = nums[i];
                }
            }
        }
    }
    
    printf("m1 = %d, m2 = %d\n", m1, m2);
    if (m1 >= m2 * 2) return index;
    return -1;
}
