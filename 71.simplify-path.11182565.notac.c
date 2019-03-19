/*
 * @lc app=leetcode.cn id=71 lang=c
 *
 * [71] 简化路径
 *
 * https://leetcode-cn.com/problems/simplify-path/description/
 *
 * algorithms
 * Medium (33.11%)
 * Total Accepted:    5.5K
 * Total Submissions: 16.5K
 * Testcase Example:  '"/home/"'
 *
 * 以 Unix 风格给出一个文件的绝对路径，你需要简化它。或者换句话说，将其转换为规范路径。
 * 
 * 在 Unix 风格的文件系统中，一个点（.）表示当前目录本身；此外，两个点 （..）
 * 表示将目录切换到上一级（指向父目录）；两者都可以是复杂相对路径的组成部分。更多信息请参阅：Linux / Unix中的绝对路径 vs 相对路径
 * 
 * 请注意，返回的规范路径必须始终以斜杠 / 开头，并且两个目录名之间必须只有一个斜杠 /。最后一个目录名（如果存在）不能以 /
 * 结尾。此外，规范路径必须是表示绝对路径的最短字符串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入："/home/"
 * 输出："/home"
 * 解释：注意，最后一个目录名后面没有斜杠。
 * 
 * 
 * 示例 2：
 * 
 * 输入："/../"
 * 输出："/"
 * 解释：从根目录向上一级是不可行的，因为根是你可以到达的最高级。
 * 
 * 
 * 示例 3：
 * 
 * 输入："/home//foo/"
 * 输出："/home/foo"
 * 解释：在规范路径中，多个连续斜杠需要用一个斜杠替换。
 * 
 * 
 * 示例 4：
 * 
 * 输入："/a/./b/../../c/"
 * 输出："/c"
 * 
 * 
 * 示例 5：
 * 
 * 输入："/a/../../b/../c//.//"
 * 输出："/c"
 * 
 * 
 * 示例 6：
 * 
 * 输入："/a//b////c/d//././/.."
 * 输出："/a/b/c"
 * 
 */
char* simplifyPath(char* path) {
    char stack[10000] = {0};
    int top = -1;
    
    char *p = path;
    while(*p != '\0')
    {
        if (*p == '/' && top != -1)
        {
            if (top >= 0 && stack[top] == '/') 
            {
                printf("ingore the duplicated /\n");
            }
            else if(top >=1 && stack[top] == '.' && stack[top-1] == '/') 
            {
                printf("ingore the current dir /./\n");
                top--;
            } else if(top >=2 && stack[top] == '.' && stack[top-1] == '.' && stack[top-2] == '/') 
            {
                printf("going back to parent dir\n");
                top -= 2;
            } else
            {
                top++;
                stack[top] = *p;
            }
        }
        else
        {
            top++;
            stack[top] = *p;
        }
        
        p++;
    }
                 
    // we have to cut the tailing /, /boo/ -> /boo, but a sigle / should not be cut;
    if (stack[top] == '/' && top != 0)
    {
        printf("a\n");
        top--;
    }
    
    if (stack[top] == '.')
    {
        if(top >= 2 && stack[top-1] == '.' && stack[top-2] == '/')
        {
            printf("b\n");
            top = top -2;
        }
        else if (top >= 1 && stack[top-1] == '/')
        {
            printf("c\n");
            top = top -1;
        }
    }
    

    if(top >= 0)
    {
        char* p = (char *)malloc(sizeof(char) * (top + 2));
        for(int i = 0; i <= top; i++)
        {
            p[i] = stack[i];
        }
        
        p[top + 1] = '\0';
        return p;
    }
    
    return NULL;
}
