/*
 * @lc app=leetcode.cn id=917 lang=c
 *
 * [917] 救生艇
 *
 * https://leetcode-cn.com/problems/reverse-only-letters/description/
 *
 * algorithms
 * Easy (44.36%)
 * Total Accepted:    2.2K
 * Total Submissions: 4.8K
 * Testcase Example:  '"ab-cd"'
 *
 * 给定一个字符串 S，返回 “反转后的” 字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入："ab-cd"
 * 输出："dc-ba"
 * 
 * 
 * 示例 2：
 * 
 * 输入："a-bC-dEf-ghIj"
 * 输出："j-Ih-gfE-dCba"
 * 
 * 
 * 示例 3：
 * 
 * 输入："Test1ng-Leet=code-Q!"
 * 输出："Qedo1ct-eeLg=ntse-T!"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * S.length <= 100
 * 33 <= S[i].ASCIIcode <= 122 
 * S 中不包含 \ or "
 * 
 * 
 */
char* reverseOnlyLetters(char* S) {
    int sLen = strlen(S);
    
    char* p1 = S;
    char* p2 = S + sLen - 1;
    
    while(!isalpha(*p1)) p1++;
    while(!isalpha(*p2)) p2--;
    
    while (p1 < p2)
    {
        //printf("*p1 = %c, *p2 = %c\n", *p1, *p2);
        char temp = *p1;
        *p1 = *p2;
        *p2 = temp;
        
        p1 = p1 + 1;
        p2 = p2 - 1;
        while(!isalpha(*p1)) p1++;
        while(!isalpha(*p2)) p2--;
    }
    
    return S;
}
