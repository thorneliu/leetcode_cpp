/*
 * @lc app=leetcode.cn id=441 lang=c
 *
 * [441] 排列硬币
 *
 * https://leetcode-cn.com/problems/arranging-coins/description/
 *
 * algorithms
 * Easy (35.44%)
 * Total Accepted:    4.9K
 * Total Submissions: 13.8K
 * Testcase Example:  '5'
 *
 * 你总共有 n 枚硬币，你需要将它们摆成一个阶梯形状，第 k 行就必须正好有 k 枚硬币。
 * 
 * 给定一个数字 n，找出可形成完整阶梯行的总行数。
 * 
 * n 是一个非负整数，并且在32位有符号整型的范围内。
 * 
 * 示例 1:
 * 
 * 
 * n = 5
 * 
 * 硬币可排列成以下几行:
 * ¤
 * ¤ ¤
 * ¤ ¤
 * 
 * 因为第三行不完整，所以返回2.
 * 
 * 
 * 示例 2:
 * 
 * 
 * n = 8
 * 
 * 硬币可排列成以下几行:
 * ¤
 * ¤ ¤
 * ¤ ¤ ¤
 * ¤ ¤
 * 
 * 因为第四行不完整，所以返回3.
 * 
 * 
 */
int arrangeCoins(int n) {
    // find the first x that (1 + x) * x /2 > n, then ans = x - 1;
    if (n == 1) return 1;
    long l = 1;
    long h = (long)n + 1;
    double nlong = (double) n;
    
    while(l < h)
    {
        long m = l + (h - l)/2;
        if (m * (m + 1) <= 2* nlong)
        {
            l = m + 1;
        }
        else
        {
            h = m;
        }
    }
    
    return l - 1;
}
