/*
 * @lc app=leetcode.cn id=949 lang=cpp
 *
 * [949] 猫和老鼠
 *
 * https://leetcode-cn.com/problems/largest-time-for-given-digits/description/
 *
 * algorithms
 * Easy (29.19%)
 * Total Accepted:    1.1K
 * Total Submissions: 3.8K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个由 4 位数字组成的数组，返回可以设置的符合 24 小时制的最大时间。
 * 
 * 最小的 24 小时制时间是 00:00，而最大的是 23:59。从 00:00 （午夜）开始算起，过得越久，时间越大。
 * 
 * 以长度为 5 的字符串返回答案。如果不能确定有效时间，则返回空字符串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[1,2,3,4]
 * 输出："23:41"
 * 
 * 
 * 示例 2：
 * 
 * 输入：[5,5,5,5]
 * 输出：""
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * A.length == 4
 * 0 <= A[i] <= 9
 * 
 * 
 */
/*
 * @lc app=leetcode.cn id=949 lang=cpp
 *
 * [949] 猫和老鼠
 *
 * https://leetcode-cn.com/problems/largest-time-for-given-digits/description/
 *
 * algorithms
 * Easy (28.70%)
 * Total Accepted:    1K
 * Total Submissions: 3.5K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个由 4 位数字组成的数组，返回可以设置的符合 24 小时制的最大时间。
 * 
 * 最小的 24 小时制时间是 00:00，而最大的是 23:59。从 00:00 （午夜）开始算起，过得越久，时间越大。
 * 
 * 以长度为 5 的字符串返回答案。如果不能确定有效时间，则返回空字符串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[1,2,3,4]
 * 输出："23:41"
 * 
 * 
 * 示例 2：
 * 
 * 输入：[5,5,5,5]
 * 输出：""
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * A.length == 4
 * 0 <= A[i] <= 9
 * 
 * 
 */
class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        assert(A.size() == 4);

        int minutesCnt = -1;
        string res;

        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A.size(); j++)
            {
                if (j == i) continue;
                for (int k = 0; k < A.size(); k++)
                {
                    if (k == i || k == j) continue;
                    for (int l = 0; l < A.size(); l++)
                    {
                        if (l == k || l == j || l == i) continue;
                        time t(A[i], A[j], A[k], A[l]);
                        if (t.getMinute() > minutesCnt)
                        {
                            minutesCnt = t.getMinute();
                            res = t.getString();
                        }
                    }
                }
            }
        }

        return res;
    }

private:
    struct time{
        int h1;
        int h2;
        int m1;
        int m2;

        time(int i, int j, int k, int l) : h1(i), h2(j), m1(k), m2(l){};

        int getMinute()
        {
            if ((h1 * 10 + h2) >= 24) return -1;
            if ((m1 * 10 + m2) >= 60) return -1;

            return (h1 * 10 + h2) * 60 + m1 * 10 + m2;
        }

        string getString()
        {
            ostringstream oss;
            oss << h1;
            oss << h2 << ":";
            oss << m1;
            oss << m2;
            return oss.str();
        }
    };
};


