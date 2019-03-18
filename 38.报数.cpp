/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 报数
 *
 * https://leetcode-cn.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (48.37%)
 * Total Accepted:    22.9K
 * Total Submissions: 47.3K
 * Testcase Example:  '1'
 *
 * 报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 1 被读作  "one 1"  ("一个一") , 即 11。
 * 11 被读作 "two 1s" ("两个一"）, 即 21。
 * 21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。
 * 
 * 给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。
 * 
 * 注意：整数顺序将表示为一个字符串。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: 1
 * 输出: "1"
 * 
 * 
 * 示例 2:
 * 
 * 输入: 4
 * 输出: "1211"
 * 
 * 
 */
class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        int i = 1;

        while (i < n)
        {
            vector<record> recList = parseString(str);
            ostringstream oss;
            for (const auto& rec : recList)
            {
                oss << rec.second << rec.first;
            }

            str = oss.str();
            i++;
        }

        return str;
    }

private:
    using record = pair<char, int>;
    vector<record> parseString(const string& str)
    {
        vector<record> res;
        if (str.empty()) return res;

        char c = str[0];
        int cnt = 1;
        auto size = str.size();

        for (int i = 1; i < size; i++)
        {
            if (str[i] == c)
            {
                cnt++;
            }
            else
            {
                res.push_back({c, cnt});
                c = str[i];
                cnt = 1;
            }
        }

        res.push_back({c, cnt});
        return res;
    }
};

