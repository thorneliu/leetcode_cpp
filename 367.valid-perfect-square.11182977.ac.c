/*
 * @lc app=leetcode.cn id=367 lang=c
 *
 * [367] 有效的完全平方数
 *
 * https://leetcode-cn.com/problems/valid-perfect-square/description/
 *
 * algorithms
 * Easy (39.83%)
 * Total Accepted:    6.3K
 * Total Submissions: 15.8K
 * Testcase Example:  '16'
 *
 * 给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。
 * 
 * 说明：不要使用任何内置的库函数，如  sqrt。
 * 
 * 示例 1：
 * 
 * 输入：16
 * 输出：True
 * 
 * 示例 2：
 * 
 * 输入：14
 * 输出：False
 * 
 * 
 */
bool isPerfectSquare(int num) {
    if (num == 1) return true;

    int l = 1;
    int h = num;
    int m = 0;
    
    while(l < h)
    {
        m = l + (h - l)/2;
        int divided = num/m;
        if (m == divided && num%m == 0) return true;
        if (m > divided) 
        {
            h = m;
        }
        else
        {
            l = m + 1;
        }
    }
    
    return false;
}
