/*
 * @lc app=leetcode.cn id=263 lang=c
 *
 * [263] 丑数
 *
 * https://leetcode-cn.com/problems/ugly-number/description/
 *
 * algorithms
 * Easy (44.48%)
 * Total Accepted:    6.2K
 * Total Submissions: 13.9K
 * Testcase Example:  '6'
 *
 * 编写一个程序判断给定的数是否为丑数。
 * 
 * 丑数就是只包含质因数 2, 3, 5 的正整数。
 * 
 * 示例 1:
 * 
 * 输入: 6
 * 输出: true
 * 解释: 6 = 2 × 3
 * 
 * 示例 2:
 * 
 * 输入: 8
 * 输出: true
 * 解释: 8 = 2 × 2 × 2
 * 
 * 
 * 示例 3:
 * 
 * 输入: 14
 * 输出: false 
 * 解释: 14 不是丑数，因为它包含了另外一个质因数 7。
 * 
 * 说明：
 * 
 * 
 * 1 是丑数。
 * 输入不会超过 32 位有符号整数的范围: [−231,  231 − 1]。
 * 
 * 
 */
bool isUgly(int num) {
    if(num==0) return false;
    
    int i;
    while((i = num/2) * 2 == num) num = i;
    while((i = num/3) * 3 == num) num = i;
    while((i = num/5) * 5 == num) num = i;

    return num == 1;
}