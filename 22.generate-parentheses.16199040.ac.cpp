/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (69.29%)
 * Total Accepted:    19.2K
 * Total Submissions: 27.6K
 * Testcase Example:  '3'
 *
 * 给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
 * 
 * 例如，给出 n = 3，生成结果为：
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 * 
 */
/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (69.12%)
 * Total Accepted:    18.2K
 * Total Submissions: 26.3K
 * Testcase Example:  '3'
 *
 * 给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
 * 
 * 例如，给出 n = 3，生成结果为：
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        bracketCnt notused = bracketCnt(n, n);
        string cur;
        permutation(cur, notused);

        return res_;
    }

private:
    vector<string> res_;
    struct bracketCnt {
        int openCnt;
        int closeCnt;

        bracketCnt(int x, int y) : openCnt(x), closeCnt(y) {};
    };

    void permutation(string cur, bracketCnt notused)
    {
        bool flag = false;
        //std::cout << cur << " : " << notused.openCnt << " " << notused.closeCnt << std::endl;
        if (notused.openCnt == 0 && notused.closeCnt == 0)
        {
            res_.push_back(cur);
            return;
        }

        if (notused.closeCnt > 0 && notused.closeCnt > notused.openCnt)
        {
            flag = true;
            notused.closeCnt = notused.closeCnt - 1;
            permutation(cur + ')', notused);
        }

        if(flag) notused.closeCnt = notused.closeCnt + 1;
        if (notused.openCnt > 0)
        {
            notused.openCnt = notused.openCnt - 1;
            permutation(cur + '(', notused);
        }
    }
};


