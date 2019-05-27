/*
 * @lc app=leetcode.cn id=58 lang=c
 *
 * [58] 最后一个单词的长度
 *
 * https://leetcode-cn.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (28.80%)
 * Total Accepted:    17.6K
 * Total Submissions: 61K
 * Testcase Example:  '"Hello World"'
 *
 * 给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。
 * 
 * 如果不存在最后一个单词，请返回 0 。
 * 
 * 说明：一个单词是指由字母组成，但不包含任何空格的字符串。
 * 
 * 示例:
 * 
 * 输入: "Hello World"
 * 输出: 5
 * 
 * 
 */
int lengthOfLastWord(char* s) {
    if(s == NULL) return 0;
    
    int res = 0;
    int strSize = strlen(s);
    bool getWord = false;

    for (int i = 0; i < strSize; i++)
    {
        if (getWord == false && s[i] != ' ')
        {
            getWord = true;
            res = 0;
        }

        if (getWord == true && s[i] == ' ')
        {
            getWord = false;
        }

        if (s[i] != ' ') res++;
    }

    return res;
}
