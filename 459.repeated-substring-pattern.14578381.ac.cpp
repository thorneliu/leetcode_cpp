/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 *
 * https://leetcode-cn.com/problems/repeated-substring-pattern/description/
 *
 * algorithms
 * Easy (38.74%)
 * Total Accepted:    3.9K
 * Total Submissions: 10.1K
 * Testcase Example:  '"abab"'
 *
 * 给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。给定的字符串只含有小写英文字母，并且长度不超过10000。
 * 
 * 示例 1:
 * 
 * 
 * 输入: "abab"
 * 
 * 输出: True
 * 
 * 解释: 可由子字符串 "ab" 重复两次构成。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: "aba"
 * 
 * 输出: False
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: "abcabcabcabc"
 * 
 * 输出: True
 * 
 * 解释: 可由子字符串 "abc" 重复四次构成。 (或者子字符串 "abcabc" 重复两次构成。)
 * 
 * 
 */
/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 *
 * https://leetcode-cn.com/problems/repeated-substring-pattern/description/
 *
 * algorithms
 * Easy (38.69%)
 * Total Accepted:    3.9K
 * Total Submissions: 10K
 * Testcase Example:  '"abab"'
 *
 * 给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。给定的字符串只含有小写英文字母，并且长度不超过10000。
 * 
 * 示例 1:
 * 
 * 
 * 输入: "abab"
 * 
 * 输出: True
 * 
 * 解释: 可由子字符串 "ab" 重复两次构成。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: "aba"
 * 
 * 输出: False
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: "abcabcabcabc"
 * 
 * 输出: True
 * 
 * 解释: 可由子字符串 "abc" 重复四次构成。 (或者子字符串 "abcabc" 重复两次构成。)
 * 
 * 
 */
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if (s.empty()) return false;

        auto size = s.size();
        vector<int> indexList;
        auto c = s[0];
        for (int i = 1; i < size; i++)
        {
            if (s[i] == c && size % i == 0) indexList.push_back(i);
        }

        for (auto idx : indexList)
        {
            if (isValidSubstring(s, idx)) return true;
        }

        return false;
    }

private:
    bool isValidSubstring(const string& s, int index)
    {
        // check if string s is one repeat pattern of (s[0]...s[index - 1])
        auto size = s.size();
        for (int j = index; j < size; j++)
        {
            if (s[j] != s[j%index]) return false;
        }

        return true;
    }
};


