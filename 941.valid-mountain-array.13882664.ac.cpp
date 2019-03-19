/*
 * @lc app=leetcode.cn id=941 lang=cpp
 *
 * [941] 按奇偶排序数组
 *
 * https://leetcode-cn.com/problems/valid-mountain-array/description/
 *
 * algorithms
 * Easy (33.13%)
 * Total Accepted:    2K
 * Total Submissions: 6.1K
 * Testcase Example:  '[2,1]'
 *
 * 给定一个整数数组 A，如果它是有效的山脉数组就返回 true，否则返回 false。
 * 
 * 让我们回顾一下，如果 A 满足下述条件，那么它是一个山脉数组：
 * 
 * 
 * A.length >= 3
 * 在 0 < i < A.length - 1 条件下，存在 i 使得：
 * 
 * A[0] < A[1] < ... A[i-1] < A[i] 
 * A[i] > A[i+1] > ... > A[B.length - 1]
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[2,1]
 * 输出：false
 * 
 * 
 * 示例 2：
 * 
 * 输入：[3,5,5]
 * 输出：false
 * 
 * 
 * 示例 3：
 * 
 * 输入：[0,3,2,1]
 * 输出：true
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= A.length <= 10000
 * 0 <= A[i] <= 10000 
 * 
 * 
 * 
 * 
 * 
 * 
 */
/*
 * @lc app=leetcode.cn id=941 lang=cpp
 *
 * [941] 按奇偶排序数组
 *
 * https://leetcode-cn.com/problems/valid-mountain-array/description/
 *
 * algorithms
 * Easy (33.23%)
 * Total Accepted:    1.8K
 * Total Submissions: 5.5K
 * Testcase Example:  '[2,1]'
 *
 * 给定一个整数数组 A，如果它是有效的山脉数组就返回 true，否则返回 false。
 * 
 * 让我们回顾一下，如果 A 满足下述条件，那么它是一个山脉数组：
 * 
 * 
 * A.length >= 3
 * 在 0 < i < A.length - 1 条件下，存在 i 使得：
 * 
 * A[0] < A[1] < ... A[i-1] < A[i] 
 * A[i] > A[i+1] > ... > A[B.length - 1]
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[2,1]
 * 输出：false
 * 
 * 
 * 示例 2：
 * 
 * 输入：[3,5,5]
 * 输出：false
 * 
 * 
 * 示例 3：
 * 
 * 输入：[0,3,2,1]
 * 输出：true
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= A.length <= 10000
 * 0 <= A[i] <= 10000 
 * 
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        auto size = A.size();
        if (size < 3) return false;

        // we have to find the maxium value and its index
        int max = A[0];
        int index = 0;
        for (int i = 1; i < size; i++)
        {
            if (max < A[i])
            {
                max = A[i];
                index = i;
            }
        }

        if (index == 0 || index == size - 1) return false;

        for (int i = 0; i < index; i++)
        {
            if (A[i] >= A[i + 1]) return false;
        }

        for (int i = index + 1; i < size; i++)
        {
            if (A[i] >= A[i-1]) return false;
        }

        return true;
    }
};


