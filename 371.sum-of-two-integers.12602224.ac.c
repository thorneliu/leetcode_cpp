/*
 * @lc app=leetcode.cn id=371 lang=c
 *
 * [371] 两整数之和
 *
 * https://leetcode-cn.com/problems/sum-of-two-integers/description/
 *
 * algorithms
 * Easy (57.37%)
 * Total Accepted:    7.3K
 * Total Submissions: 12.8K
 * Testcase Example:  '1\n2'
 *
 * 不使用运算符 + 和 - ​​​​​​​，计算两整数 ​​​​​​​a 、b ​​​​​​​之和。
 * 
 * 示例 1:
 * 
 * 输入: a = 1, b = 2
 * 输出: 3
 * 
 * 
 * 示例 2:
 * 
 * 输入: a = -2, b = 3
 * 输出: 1
 * 
 */
int getSum(int a, int b) {
    int res = 0;
    int carry = 0;
    int biti = 0;
    for (int i = 0; i < 32; i++)
    {
        int ai = (a >> i) & 0x1;
        int bi = (b >> i) & 0x1;
        
        if (carry == 0)
        {
            biti = ai ^ bi;
            carry = ai & bi;
        }
        else
        {
            biti = (~(ai ^ bi)) & 0x1;
            carry = ai | bi;
        }
        
        res = res | (biti << i);
    }
    
    return res;
}
