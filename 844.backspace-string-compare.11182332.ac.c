/*
 * @lc app=leetcode.cn id=844 lang=c
 *
 * [844] Backspace String Compare
 *
 * https://leetcode-cn.com/problems/backspace-string-compare/description/
 *
 * algorithms
 * Easy (45.37%)
 * Total Accepted:    4.1K
 * Total Submissions: 9K
 * Testcase Example:  '"ab#c"\n"ad#c"'
 *
 * 给定 S 和 T 两个字符串，当它们分别被输入到空白的文本编辑器后，判断二者是否相等，并返回结果。 # 代表退格字符。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：S = "ab#c", T = "ad#c"
 * 输出：true
 * 解释：S 和 T 都会变成 “ac”。
 * 
 * 
 * 示例 2：
 * 
 * 输入：S = "ab##", T = "c#d#"
 * 输出：true
 * 解释：S 和 T 都会变成 “”。
 * 
 * 
 * 示例 3：
 * 
 * 输入：S = "a##c", T = "#a#c"
 * 输出：true
 * 解释：S 和 T 都会变成 “c”。
 * 
 * 
 * 示例 4：
 * 
 * 输入：S = "a#c", T = "b"
 * 输出：false
 * 解释：S 会变成 “c”，但 T 仍然是 “b”。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= S.length <= 200
 * 1 <= T.length <= 200
 * S 和 T 只含有小写字母以及字符 '#'。
 * 
 * 
 * 
 * 
 */
bool backspaceCompare(char* S, char* T) {
    if (NULL == S || NULL == T) return 0;
    char stack1[200];
    char stack2[200];
    
    int top1 = 0;
    int top2 = 0;
    char *p1 = S;
    char *p2 = T;
    
    while(*p1 != '\0')
    {
        if (*p1 != '#')
        {
            stack1[top1] = *p1;
            top1++;
        }
        else
        {
            if (top1 == 0)
            {
                top1 = 0;
            }
            else
            {
                top1 = top1 - 1;
            }
        }
        
        p1++;
    }
    
    while(*p2 != '\0')
    {
        if (*p2 != '#')
        {
            stack2[top2] = *p2;
            top2++;
        }
        else
        {
            if (top2 == 0)
            {
                top2 = 0;
            }
            else
            {
                top2 = top2 - 1;
            }
        }
        
        p2++;
    }
    
    if (top1 != top2) 
    {
        return 0;
    }
    else
    {
        int i = 0;
        for (i = 0; i < top1; i++)
        {
            if (stack1[i] != stack2[i])
            {
                return 0;                
            }
        }
        
        return 1;
    }
}
