/*
 * @lc app=leetcode.cn id=476 lang=c
 *
 * [476] 数字的补数
 *
 * https://leetcode-cn.com/problems/number-complement/description/
 *
 * algorithms
 * Easy (66.70%)
 * Total Accepted:    7K
 * Total Submissions: 10.5K
 * Testcase Example:  '5'
 *
 * 给定一个正整数，输出它的补数。补数是对该数的二进制表示取反。
 * 
 * 注意:
 * 
 * 
 * 给定的整数保证在32位带符号整数的范围内。
 * 你可以假定二进制数不包含前导零位。
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: 5
 * 输出: 2
 * 解释: 5的二进制表示为101（没有前导零位），其补数为010。所以你需要输出2。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: 1
 * 输出: 0
 * 解释: 1的二进制表示为1（没有前导零位），其补数为0。所以你需要输出0。
 * 
 * 
 */
int findComplement(int num) {
    int fullOneValue = 0;
    char bits[31] = {0};
    int bitLength = 0;
    
    int x;
    for (int i = 0; i < 31; i++)
    {
        x = 1 << i;
        fullOneValue += x;
        if (x & num) bits[i] = 1;
        if (num <= fullOneValue) 
        {
            bitLength = i;
            break;
        }
    }
    
    int res = 0;
    for (int i = 0; i <= bitLength; i++)
    {
        if (bits[i] == 0) 
        {
            res += (1 << i);
        }
    }
    
    return res;
}
