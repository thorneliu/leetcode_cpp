/*
 * @lc app=leetcode.cn id=537 lang=c
 *
 * [537] 复数乘法
 *
 * https://leetcode-cn.com/problems/complex-number-multiplication/description/
 *
 * algorithms
 * Medium (61.59%)
 * Total Accepted:    1.4K
 * Total Submissions: 2.2K
 * Testcase Example:  '"1+1i"\n"1+1i"'
 *
 * 给定两个表示复数的字符串。
 * 
 * 返回表示它们乘积的字符串。注意，根据定义 i2 = -1 。
 * 
 * 示例 1:
 * 
 * 
 * 输入: "1+1i", "1+1i"
 * 输出: "0+2i"
 * 解释: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i ，你需要将它转换为 0+2i 的形式。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: "1+-1i", "1+-1i"
 * 输出: "0+-2i"
 * 解释: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i ，你需要将它转换为 0+-2i 的形式。 
 * 
 * 
 * 注意:
 * 
 * 
 * 输入字符串不包含额外的空格。
 * 输入字符串将以 a+bi 的形式给出，其中整数 a 和 b 的范围均在 [-100, 100] 之间。输出也应当符合这种形式。
 * 
 * 
 */
typedef struct{
    int real;
    int imag;
}ComplexNumber;

ComplexNumber getComplexNumber(char *str) {
    ComplexNumber c;
    char *p = str;
    
    int real = 0;
    bool isNegetive = false;
    while(*p != '+')
    {
        if(*p == '-') {
           isNegetive = true; 
        }
        
        if (isdigit(*p)) {
            real = real * 10 + (*p) - '0';
        }
        
        p++;
    }
    
    if (isNegetive) real = real * (-1);
    
    int imag = 0;
    isNegetive = false;
    while(*p != '\0')
    {
        if(*p == '-'){
            isNegetive = true;
        }
        
        if (isdigit(*p)) {
            imag = imag * 10 + (*p) - '0';
        }
        
        p++;
    }
    
    if (isNegetive) imag = imag * (-1);
    c.real = real;
    c.imag = imag;
    
    return c;
}

char* complexNumberMultiply(char* a, char* b) {
       ComplexNumber ca = getComplexNumber(a);
       ComplexNumber cb = getComplexNumber(b);
       printf("ca  = %d + %di\n", ca.real, ca.imag);
       printf("cb  = %d + %di\n", cb.real, cb.imag);
    
       int resReal = ca.real * cb.real - ca.imag * cb.imag;
       int resImag = ca.imag * cb.real + ca.real * cb.imag;
       
        char *c = (char *)malloc(sizeof(char) * 14);
        sprintf(c,"%d+%di", resReal, resImag);
        return c;
}
