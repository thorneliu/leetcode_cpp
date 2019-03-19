/*
 * @lc app=leetcode.cn id=415 lang=c
 *
 * [415] 字符串相加
 *
 * https://leetcode-cn.com/problems/add-strings/description/
 *
 * algorithms
 * Easy (43.18%)
 * Total Accepted:    4.8K
 * Total Submissions: 11K
 * Testcase Example:  '"0"\n"0"'
 *
 * 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
 * 
 * 注意：
 * 
 * 
 * num1 和num2 的长度都小于 5100.
 * num1 和num2 都只包含数字 0-9.
 * num1 和num2 都不包含任何前导零。
 * 你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。
 * 
 * 
 */
char addChars(char c1, char c2, char* carryOn)
{
    int op1 = c1 - '0';
    int op2 = c2 - '0';
    
    int res = op1 + op2 + *carryOn;
    if (res >= 10) 
    {
        res = res - 10;
        *carryOn = 1;
    }
    else
    {
        *carryOn = 0;
    }
    
    return res + '0';
}

char* addStrings(char* num1, char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    
    char carryOn = 0;
    char stack[5100] = {0};
    int top = -1;
    
    int i = len1 - 1;
    int j = len2 - 1;
    
    char op1 = 0;
    char op2 = 0;
    
    while (i >= 0 || j >= 0)
    {
        op1 = i >= 0 ? num1[i] : '0';
        op2 = j >= 0 ? num2[j] : '0';
        
        top++;
        stack[top] = addChars(op1, op2, &carryOn);
        i--;
        j--;
    }
    
    if (carryOn == 1) 
    {
        top++;
        stack[top] = carryOn + '0';
    }
    
    int returnSize = top + 2;
    char* res =  (char *)malloc(sizeof(char) * returnSize);
    for (int i = 0; i <= top; i++) res[top - i] = stack[i];
    res[top + 1] = '\0';
    
    return res;
}
