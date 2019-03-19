/*
 * @lc app=leetcode.cn id=125 lang=c
 *
 * [125] 验证回文串
 *
 * https://leetcode-cn.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (38.02%)
 * Total Accepted:    23.1K
 * Total Submissions: 60.7K
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
 * 
 * 说明：本题中，我们将空字符串定义为有效的回文串。
 * 
 * 示例 1:
 * 
 * 输入: "A man, a plan, a canal: Panama"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "race a car"
 * 输出: false
 * 
 * 
 */
bool isSameAlplaNum(char c1, char c2)
{
    if(isalpha(c1) && isalpha(c2))
    {
        return (tolower(c1) - tolower(c2)) == 0;
    }
    
    return (c1 - c2) == 0;
}

bool isPalindrome(char* s) {
    if (s == NULL) return true;
    int len = strlen(s);
    char* p1 = s;
    char* p2 = s + len - 1;
    
    while(p1 < p2)
    {
        while(!isalnum(*p1) && p1 < (s + len -1)) p1++;
        while(!isalnum(*p2) && p2 > s) p2--;
        if (!isSameAlplaNum(*p1, *p2))
        {
            break;
        }
        
        p1++;
        p2--;
    }
    
    return (p1 >= p2);
}
