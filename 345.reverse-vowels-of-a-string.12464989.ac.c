/*
 * @lc app=leetcode.cn id=345 lang=c
 *
 * [345] 反转字符串中的元音字母
 *
 * https://leetcode-cn.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (46.10%)
 * Total Accepted:    6.6K
 * Total Submissions: 14.3K
 * Testcase Example:  '"hello"'
 *
 * 编写一个函数，以字符串作为输入，反转该字符串中的元音字母。
 * 
 * 示例 1:
 * 
 * 输入: "hello"
 * 输出: "holle"
 * 
 * 
 * 示例 2:
 * 
 * 输入: "leetcode"
 * 输出: "leotcede"
 * 
 * 说明:
 * 元音字母不包含字母"y"。
 * 
 */
bool isVoewlChar(char c)
{
    char c1 = tolower(c);
    return c1 == 'a' 
        || c1 == 'e'
        || c1 == 'i'
        || c1 == 'o'
        || c1 == 'u';
}

char* reverseVowels(char* s) {
    if (NULL == s) return s;
    
    int len = strlen(s);
    char* p1 = s;
    char* p2 = s + len - 1;
    
    while(p1 < p2)
    {
        while(!isVoewlChar(*p1) && p1 < p2) p1++;
        while(!isVoewlChar(*p2) && p2 > s) p2--;
        
        if (p1 < p2)
        {
            char temp = *p1;
            *p1 = *p2;
            *p2 = temp;
        }
        
        p1++;
        p2--;
    }
    
    return s;
}
