/*
 * @lc app=leetcode.cn id=961 lang=cpp
 *
 * [961] 长按键入
 *
 * https://leetcode-cn.com/problems/n-repeated-element-in-size-2n-array/description/
 *
 * algorithms
 * Easy (69.80%)
 * Total Accepted:    5.3K
 * Total Submissions: 7.6K
 * Testcase Example:  '[1,2,3,3]'
 *
 * 在大小为 2N 的数组 A 中有 N+1 个不同的元素，其中有一个元素重复了 N 次。
 * 
 * 返回重复了 N 次的那个元素。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[1,2,3,3]
 * 输出：3
 * 
 * 
 * 示例 2：
 * 
 * 输入：[2,1,2,5,3,2]
 * 输出：2
 * 
 * 
 * 示例 3：
 * 
 * 输入：[5,1,5,2,5,3,5,4]
 * 输出：5
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 4 <= A.length <= 10000
 * 0 <= A[i] < 10000
 * A.length 为偶数
 * 
 * 
 */
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        sort(A.begin(), A.end());
        int len = A.size();
        if (A[0] == A[1]) return A[0];
        if (A[len-1] == A[len - 2]) return A[len-1];
        return A[len/2];
    }
};
