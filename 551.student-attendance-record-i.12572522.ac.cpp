/*
 * @lc app=leetcode.cn id=551 lang=cpp
 *
 * [551] 学生出勤记录 I
 *
 * https://leetcode-cn.com/problems/student-attendance-record-i/description/
 *
 * algorithms
 * Easy (46.26%)
 * Total Accepted:    3.5K
 * Total Submissions: 7.6K
 * Testcase Example:  '"PPALLP"'
 *
 * 给定一个字符串来代表一个学生的出勤记录，这个记录仅包含以下三个字符：
 * 
 * 
 * 'A' : Absent，缺勤
 * 'L' : Late，迟到
 * 'P' : Present，到场
 * 
 * 
 * 如果一个学生的出勤记录中不超过一个'A'(缺勤)并且不超过两个连续的'L'(迟到),那么这个学生会被奖赏。
 * 
 * 你需要根据这个学生的出勤记录判断他是否会被奖赏。
 * 
 * 示例 1:
 * 
 * 输入: "PPALLP"
 * 输出: True
 * 
 * 
 * 示例 2:
 * 
 * 输入: "PPALLL"
 * 输出: False
 * 
 * 
 */
class Solution {
public:
    bool checkRecord(string s) {
        int Acnt = 0;
        int Lstart = -1;
        int maxLen = 0;
        int strlen = s.size();
        
        for (int i = 0; i < strlen; i++)
        {
            auto c = s[i];
            if (c == 'A') Acnt++;
            if (c == 'L' && Lstart == -1) Lstart = i;
            if (Lstart != -1)
            {
                if (c != 'L')
                {
                    maxLen = max(maxLen, i - Lstart);
                    Lstart = -1;
                }
                else
                {
                    maxLen = max(maxLen, i - Lstart + 1);
                }
            }
        }

        return Acnt <= 1 && maxLen <= 2;
    }
};
