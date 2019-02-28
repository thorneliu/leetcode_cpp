/*
 * @lc app=leetcode.cn id=171 lang=c
 *
 * [171] Excel表列序号
 *
 * https://leetcode-cn.com/problems/excel-sheet-column-number/description/
 *
 * algorithms
 * Easy (63.22%)
 * Total Accepted:    9.1K
 * Total Submissions: 14.4K
 * Testcase Example:  '"A"'
 *
 * 给定一个Excel表格中的列名称，返回其相应的列序号。
 * 
 * 例如，
 * 
 * ⁠   A -> 1
 * ⁠   B -> 2
 * ⁠   C -> 3
 * ⁠   ...
 * ⁠   Z -> 26
 * ⁠   AA -> 27
 * ⁠   AB -> 28 
 * ⁠   ...
 * 
 * 
 * 示例 1:
 * 
 * 输入: "A"
 * 输出: 1
 * 
 * 
 * 示例 2:
 * 
 * 输入: "AB"
 * 输出: 28
 * 
 * 
 * 示例 3:
 * 
 * 输入: "ZY"
 * 输出: 701
 * 
 * 致谢：
 * 特别感谢 @ts 添加此问题并创建所有测试用例。
 * 
 */
#include <ctype.h>

int char2num(char c)
{
    if(isalpha(c))
    {
        if(islower(c))
        return c - 'a' + 1;
        else
        return c - 'A' + 1;
    }
    else
        return 0;
}

int titleToNumber(char* s) {
    if (NULL == s)
    {
        printf("invalid parameters.\n");
        return 0;
    }
    
    int result = 0;
    char *p = s;
    result = char2num(*p);
    p++;
    for (; *p != '\0'; p++)
    {
        result = result * 26 + char2num(*p);
    }
    
    return result;
}


