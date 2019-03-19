/*
 * @lc app=leetcode.cn id=693 lang=c
 *
 * [693] 交替位二进制数
 *
 * https://leetcode-cn.com/problems/binary-number-with-alternating-bits/description/
 *
 * algorithms
 * Easy (59.65%)
 * Total Accepted:    4.5K
 * Total Submissions: 7.6K
 * Testcase Example:  '5'
 *
 * 给定一个正整数，检查他是否为交替位二进制数：换句话说，就是他的二进制数相邻的两个位数永不相等。
 * 
 * 示例 1:
 * 
 * 
 * 输入: 5
 * 输出: True
 * 解释:
 * 5的二进制数是: 101
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: 7
 * 输出: False
 * 解释:
 * 7的二进制数是: 111
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: 11
 * 输出: False
 * 解释:
 * 11的二进制数是: 1011
 * 
 * 
 * 示例 4:
 * 
 * 
 * 输入: 10
 * 输出: True
 * 解释:
 * 10的二进制数是: 1010
 * 
 * 
 */
bool hasAlternatingBits(int n) {
    char bits[32] = {0};
    int cnt = 0;
    while(n != 0)
    {
        bits[cnt++] = n & 0x1;
        n = n >> 1;
    }
    
    for (int i = 1; i < cnt; i++)
    {
        if (bits[i] == bits[i-1]) return false;
    }
    
    return true;
}
