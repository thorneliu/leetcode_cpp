/*
 * @lc app=leetcode.cn id=922 lang=c
 *
 * [922] 可能的二分法
 *
 * https://leetcode-cn.com/problems/sort-array-by-parity-ii/description/
 *
 * algorithms
 * Easy (67.20%)
 * Total Accepted:    6.5K
 * Total Submissions: 9.6K
 * Testcase Example:  '[4,2,5,7]'
 *
 * 给定一个非负整数数组 A， A 中一半整数是奇数，一半整数是偶数。
 * 
 * 对数组进行排序，以便当 A[i] 为奇数时，i 也是奇数；当 A[i] 为偶数时， i 也是偶数。
 * 
 * 你可以返回任何满足上述条件的数组作为答案。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：[4,2,5,7]
 * 输出：[4,5,2,7]
 * 解释：[4,7,2,5]，[2,5,4,7]，[2,7,4,5] 也会被接受。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= A.length <= 20000
 * A.length % 2 == 0
 * 0 <= A[i] <= 1000
 * 
 * 
 * 
 * 
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParityII(int* A, int ASize, int* returnSize) {
    *returnSize = ASize;
    int* p = (int*)malloc(sizeof(int) * ASize);
    memset(p, 0, sizeof(int) * ASize);
    
    int* p1 = p;
    int* p2 = p+1;
    int element = 0;
    for (int i = 0; i < ASize; i++)
    {
        element = A[i];
        if ((element % 2) == 0)
        {
            *p1 = element;
            p1 += 2;
        }
        else
        {
            *p2 = element;
            p2 +=2;
        }
    }
    
    return p;
} 

