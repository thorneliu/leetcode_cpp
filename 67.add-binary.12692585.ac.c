/*
 * @lc app=leetcode.cn id=67 lang=c
 *
 * [67] 二进制求和
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (46.50%)
 * Total Accepted:    16.6K
 * Total Submissions: 35.6K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给定两个二进制字符串，返回他们的和（用二进制表示）。
 * 
 * 输入为非空字符串且只包含数字 1 和 0。
 * 
 * 示例 1:
 * 
 * 输入: a = "11", b = "1"
 * 输出: "100"
 * 
 * 示例 2:
 * 
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 * 
 */
#define MAX(a, b) ((a) > (b) ? (a):(b))

char binAdd(char op1, char op2, bool *bcarryOver)
{
    if (!*bcarryOver)
    {
        if(op1 == '0' && op2 == '0')
        {
            *bcarryOver = false;
            return '0';
        }

        if((op1 == '0' && op2 == '1') || (op1 == '1' && op2 == '0'))
        {
            *bcarryOver = false;
            return '1';
        }

        if(op1 == '1' && op2 == '1')
        {
            *bcarryOver = true;
            return '0';
        }
    }
    else
    {

        if(op1 == '0' && op2 == '0')
        {
            *bcarryOver = false;
            return '1';
        }
        if((op1 == '0' && op2 == '1') || (op1 == '1' && op2 == '0'))
        {
            *bcarryOver = true;
            return '0';
        }
        if(op1 == '1' && op2 == '1')
        {
            *bcarryOver = true;
            return '1';
        }
    }

    return '0';
}

char* addBinary(char* a, char* b) {
    if (a == NULL || b == NULL) return NULL;

    char *pa = a;
    char *pb = b;

    int la = 0;
    int lb = 0;

    while(*pa != '\0')
    {la++; pa++;}
    while(*pb != '\0')
    {lb++; pb++;}

    char result[MAX(la, lb) + 1];
    pa--; pb--;
    bool bcarryOver = false;

    int numofBit = 0;
    char opa = '0';
    char opb = '0';

    while (pa >= a || pb >= b)
    {
        opa = (pa >= a ? *pa : '0');
        opb = (pb >= b ? *pb : '0');

        numofBit++;
        result[numofBit - 1] = binAdd(opa, opb, &bcarryOver);
        
        if(pa >= a) pa--;
        if(pb >= b) pb--;
    }

    if(bcarryOver)
    {
        numofBit++;
        result[numofBit-1] = '1';
    }

    char *str = (char *)malloc((numofBit+1)*sizeof(char));
    *(str + numofBit) = '\0';
    int j;
    for (j = 0; j < numofBit; j++)
    {
        *(str + numofBit - j -1) = result[j];
    }

    return str;
}
