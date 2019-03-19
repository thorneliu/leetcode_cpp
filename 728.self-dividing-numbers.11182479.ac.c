/*
 * @lc app=leetcode.cn id=728 lang=c
 *
 * [728] 自除数
 *
 * https://leetcode-cn.com/problems/self-dividing-numbers/description/
 *
 * algorithms
 * Easy (65.79%)
 * Total Accepted:    6.7K
 * Total Submissions: 10.3K
 * Testcase Example:  '1\n22'
 *
 * 自除数 是指可以被它包含的每一位数除尽的数。
 * 
 * 例如，128 是一个自除数，因为 128 % 1 == 0，128 % 2 == 0，128 % 8 == 0。
 * 
 * 还有，自除数不允许包含 0 。
 * 
 * 给定上边界和下边界数字，输出一个列表，列表的元素是边界（含边界）内所有的自除数。
 * 
 * 示例 1：
 * 
 * 
 * 输入： 
 * 上边界left = 1, 下边界right = 22
 * 输出： [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
 * 
 * 
 * 注意：
 * 
 * 
 * 每个输入参数的边界满足 1 <= left <= right <= 10000。
 * 
 * 
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool isSelfDivisible(int x)
{
    int y = x;
    int digits[6] = {0}; // A int[6] to hold all its digits
    int cnt = 0;
    while (x != 0)
    {
        int digit = x % 10;
        if (digit == 0) return false;
        
        digits[cnt++] = digit;
        x /= 10;
    }
    
    for (int i = 0; i < cnt; i++)
    {
        if (y % digits[i] != 0) return false;
    }
    
    return true;
}

int* selfDividingNumbers(int left, int right, int* returnSize) {
    int resultArray[1000] = {0};
    int size = 0;
    for (int i = left; i <= right; i++)
    {
        if (isSelfDivisible(i)) resultArray[size++] = i;
    }
    
    int *res = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
    {
        res[i] = resultArray[i];
    }
    
    *returnSize = size;
    return res;
}
