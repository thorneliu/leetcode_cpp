/*
 * @lc app=leetcode.cn id=119 lang=c
 *
 * [119] 杨辉三角 II
 *
 * https://leetcode-cn.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (53.99%)
 * Total Accepted:    10K
 * Total Submissions: 18.6K
 * Testcase Example:  '3'
 *
 * 给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出: [1,3,3,1]
 * 
 * 
 * 进阶：
 * 
 * 你可以优化你的算法到 O(k) 空间复杂度吗？
 * 
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    if(rowIndex < 0) {
        *returnSize = 0;
        return NULL;
    }
    
    int a[34] = {1};
    for (int i = 1; i <= rowIndex; i++)
    {
        //a[0] = 1;
        for (int j = i; j >= 1; j--)
        {
            a[j] = a[j-1] + a[j];
        }
    }
    
    int *p = (int*)malloc(sizeof(int) * (rowIndex + 1));
    for (int i = 0; i <= rowIndex; i++)
    {
        p[i] = a[i];
    }
    *returnSize = rowIndex + 1;
    
    return p;
}
