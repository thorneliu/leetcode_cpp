/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 *
 * https://leetcode-cn.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (34.57%)
 * Total Accepted:    23.6K
 * Total Submissions: 68.4K
 * Testcase Example:  '4'
 *
 * 实现 int sqrt(int x) 函数。
 * 
 * 计算并返回 x 的平方根，其中 x 是非负整数。
 * 
 * 由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
 * 
 * 示例 1:
 * 
 * 输入: 4
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: 8
 * 输出: 2
 * 说明: 8 的平方根是 2.82842..., 
 * 由于返回类型是整数，小数部分将被舍去。
 * 
 * 
 */
class Solution {
public:
    int mySqrt(int x) {
        if (1 == x) return 1;
        
        int l = 1;
        int h = x;
        
        while(l < h)
        {
            long mid = l + (h - l)/2;
            if (mid * mid > x) // find the smallest value t with t * t > x
            {
                h = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        
        return l - 1; //target = t - 1
    }
};