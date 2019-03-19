/*
 * @lc app=leetcode.cn id=852 lang=c
 *
 * [852] 适龄的朋友
 *
 * https://leetcode-cn.com/problems/peak-index-in-a-mountain-array/description/
 *
 * algorithms
 * Easy (66.38%)
 * Total Accepted:    8.1K
 * Total Submissions: 12.1K
 * Testcase Example:  '[0,1,0]'
 *
 * 我们把符合下列属性的数组 A 称作山脉：
 * 
 * 
 * A.length >= 3
 * 存在 0 < i < A.length - 1 使得A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... >
 * A[A.length - 1]
 * 
 * 
 * 给定一个确定为山脉的数组，返回任何满足 A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... >
 * A[A.length - 1] 的 i 的值。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[0,1,0]
 * 输出：1
 * 
 * 
 * 示例 2：
 * 
 * 输入：[0,2,1,0]
 * 输出：1
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 <= A.length <= 10000
 * 0 <= A[i] <= 10^6
 * A 是如上定义的山脉
 * 
 * 
 * 
 * 
 */
int max(int *A, int l, int r)
{
    int m = l + (r -l)/2;
    if (r > l + 1)
    {
        int a = max(A, l, m);
        int b = max(A, m, r);
        return A[a] > A[b] ? a : b;
    }
    else
    {
        return A[l] > A[r] ? l : r;
    }
}


int peakIndexInMountainArray(int* A, int ASize) {
    // to find the max num in this array
    return max(A, 0, ASize - 1);
}
