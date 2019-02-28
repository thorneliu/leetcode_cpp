/*
 * @lc app=leetcode.cn id=28 lang=c
 *
 * [28] 实现strStr()
 *
 * https://leetcode-cn.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (37.64%)
 * Total Accepted:    37K
 * Total Submissions: 98.2K
 * Testcase Example:  '"hello"\n"ll"'
 *
 * 实现 strStr() 函数。
 * 
 * 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置
 * (从0开始)。如果不存在，则返回  -1。
 * 
 * 示例 1:
 * 
 * 输入: haystack = "hello", needle = "ll"
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: haystack = "aaaaa", needle = "bba"
 * 输出: -1
 * 
 * 
 * 说明:
 * 
 * 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
 * 
 * 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
 * 
 */
int isStringMatch(char* p1, char* p2);

int strStr(char* haystack, char* needle) {
    if (NULL == haystack || NULL == needle) return -1;
    if (*haystack == '\0' && *needle == '\0') return 0;
    
    char *p1 = haystack;
    char *p2 = needle;
    int index = 0;
    while(*p1 != '\0')
    {
        if (isStringMatch(p1, p2))
        {
            return index;
        }
        else
        {
            p1++;
            index++;
        }
    }
    
    return -1;   
}

int isStringMatch(char* p1, char* p2)
{
    while(*p1 != '\0' && *p2 != '\0')
    {
        if(*p1 == *p2)
        {
            p1++;
            p2++;
        }
        else
        {
            return 0;
        }
    }
    
    if (*p2 == '\0')
    {
        return 1;
    }
    else{
        return 0;
    }
}
