/*
 * @lc app=leetcode.cn id=867 lang=c
 *
 * [867] 新21点
 *
 * https://leetcode-cn.com/problems/transpose-matrix/description/
 *
 * algorithms
 * Easy (62.61%)
 * Total Accepted:    6.9K
 * Total Submissions: 11.1K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给定一个矩阵 A， 返回 A 的转置矩阵。
 * 
 * 矩阵的转置是指将矩阵的主对角线翻转，交换矩阵的行索引与列索引。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[[1,4,7],[2,5,8],[3,6,9]]
 * 
 * 
 * 示例 2：
 * 
 * 输入：[[1,2,3],[4,5,6]]
 * 输出：[[1,4],[2,5],[3,6]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= A.length <= 1000
 * 1 <= A[0].length <= 1000
 * 
 * 
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** transpose(int** A, int ARowSize, int *AColSizes, int** columnSizes, int* returnSize) {
    *returnSize = AColSizes[0];
    *columnSizes = (int *)malloc(sizeof(int) * AColSizes[0]);

    int**res = (int **)malloc(sizeof(int *) * AColSizes[0]);
    for(int i = 0; i < AColSizes[0]; i++)
    {
        int *p = (int *)malloc(sizeof(int) * ARowSize);
        for(int j = 0; j < ARowSize; j++)
        {
            p[j] = A[j][i];
        }
        
        res[i] = p;
        (*columnSizes)[i] = ARowSize;
    }
    
    return res;
}
