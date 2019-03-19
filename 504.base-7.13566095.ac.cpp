/*
 * @lc app=leetcode.cn id=504 lang=cpp
 *
 * [504] 七进制数
 *
 * https://leetcode-cn.com/problems/base-7/description/
 *
 * algorithms
 * Easy (41.99%)
 * Total Accepted:    2.5K
 * Total Submissions: 6K
 * Testcase Example:  '100'
 *
 * 给定一个整数，将其转化为7进制，并以字符串形式输出。
 * 
 * 示例 1:
 * 
 * 
 * 输入: 100
 * 输出: "202"
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: -7
 * 输出: "-10"
 * 
 * 
 * 注意: 输入范围是 [-1e7, 1e7] 。
 * 
 */
/*
 * @lc app=leetcode.cn id=504 lang=cpp
 *
 * [504] 七进制数
 *
 * https://leetcode-cn.com/problems/base-7/description/
 *
 * algorithms
 * Easy (41.69%)
 * Total Accepted:    2.5K
 * Total Submissions: 6K
 * Testcase Example:  '100'
 *
 * 给定一个整数，将其转化为7进制，并以字符串形式输出。
 * 
 * 示例 1:
 * 
 * 
 * 输入: 100
 * 输出: "202"
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: -7
 * 输出: "-10"
 * 
 * 
 * 注意: 输入范围是 [-1e7, 1e7] 。
 * 
 */
class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return std::string("0");
        
        string res;
        bool negetive = (num < 0);
        long Num = negetive ? (-1 * long(num)) : num;
        while(Num)
        {
            int digit = Num % 7;
            Num = Num / 7;

            res += std::to_string(digit);
        }
        if (negetive) res += "-";
        std::reverse(res.begin(), res.end());

        return res;
    }
};


