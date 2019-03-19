/*
 * @lc app=leetcode.cn id=905 lang=c
 *
 * [905] 最长的斐波那契子序列的长度
 *
 * https://leetcode-cn.com/problems/sort-array-by-parity/description/
 *
 * algorithms
 * Easy (69.46%)
 * Total Accepted:    11.7K
 * Total Submissions: 16.9K
 * Testcase Example:  '[3,1,2,4]'
 *
 * 给定一个非负整数数组 A，返回一个由 A 的所有偶数元素组成的数组，后面跟 A 的所有奇数元素。
 * 
 * 你可以返回满足此条件的任何数组作为答案。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：[3,1,2,4]
 * 输出：[2,4,3,1]
 * 输出 [4,2,3,1]，[2,4,1,3] 和 [4,2,1,3] 也会被接受。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= A.length <= 5000
 * 0 <= A[i] <= 5000
 * 
 * 
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* A, int ASize, int* returnSize) {
    int* p = (int*)malloc(sizeof(int) * ASize);
    memset(p, 0, sizeof(int) * ASize);
    *returnSize = ASize;
    
    int* p1 = p;
    int* p2 = p + ASize - 1;
    
    for (int i = 0; i < ASize; i++)
    {
        int element = A[i];
        if(element % 2 == 0)
        {
            // even
            *p1 = element;
            p1++;
        }
        else
        {
           *p2 = element;
            p2--;
        }
    }
    
    return p;
}
