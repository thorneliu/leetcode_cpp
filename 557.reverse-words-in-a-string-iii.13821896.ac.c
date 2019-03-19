/*
 * @lc app=leetcode.cn id=557 lang=c
 *
 * [557] 反转字符串中的单词 III
 *
 * https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/description/
 *
 * algorithms
 * Easy (63.05%)
 * Total Accepted:    11.4K
 * Total Submissions: 18.1K
 * Testcase Example:  '"Let\'s take LeetCode contest"'
 *
 * 给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
 * 
 * 示例 1:
 * 
 * 
 * 输入: "Let's take LeetCode contest"
 * 输出: "s'teL ekat edoCteeL tsetnoc" 
 * 
 * 
 * 注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。
 * 
 */
void reverseString(char* p1, char* p2)
{
    while(p1 < p2)
    {
        char tmp = *p1;
        *p1 = *p2;
        *p2 = tmp;
        p1++;
        p2--;
    }

    return;
}

char* reverseWords(char* s) {
    if (s == NULL || strlen(s) <= 0) return s;

    char *p1 = s, *p2 = s;
    while(*p1 != '\0')
    {
        while(*p1 == ' ' && *p1 != '\0') p1++;
        p2 = p1;
        while(*p2 != ' ' && *p2 != '\0') p2++;

        reverseString(p1, p2 - 1);
        p1 = p2;
    }
 
    return s;
}
