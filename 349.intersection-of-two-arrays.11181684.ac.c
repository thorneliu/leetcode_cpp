/*
 * @lc app=leetcode.cn id=349 lang=c
 *
 * [349] 两个数组的交集
 *
 * https://leetcode-cn.com/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (59.70%)
 * Total Accepted:    13.5K
 * Total Submissions: 22.7K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * 给定两个数组，编写一个函数来计算它们的交集。
 * 
 * 示例 1:
 * 
 * 输入: nums1 = [1,2,2,1], nums2 = [2,2]
 * 输出: [2]
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * 输出: [9,4]
 * 
 * 说明:
 * 
 * 
 * 输出结果中的每个元素一定是唯一的。
 * 我们可以不考虑输出结果的顺序。
 * 
 * 
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX(a,b) ((a) > (b) ? (a) : (b))

bool eleInArray(int* array, int size, int val)
{
    if (NULL == array || size <=0) return false;
    
    int i = 0;
    for(i = 0; i < size; i++)
    {
        if (val == array[i])
        return true;
    }
    
    return false;
}
 
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    if (NULL == nums1 || NULL == nums2 || NULL == returnSize ||
        nums1Size <= 0 ||
        nums2Size <= 0)
        return NULL;
        
    int maxSize = MAX(nums1Size, nums2Size);
    int* p = (int *)malloc(maxSize * sizeof(int));
    int  eleCnt = 0;
    
    int i = 0;
    for (i = 0; i < nums1Size; i++)
    {
        int val = nums1[i];
        if(eleInArray(nums2, nums2Size, val) && 
           !eleInArray(p, eleCnt, val))
           {
               p[eleCnt] = val;
               eleCnt++;
           }
    }
    
    *returnSize = eleCnt;
    return p;
}
