/*
 * @lc app=leetcode.cn id=821 lang=c
 *
 * [821] 打砖块
 *
 * https://leetcode-cn.com/problems/shortest-distance-to-a-character/description/
 *
 * algorithms
 * Easy (62.16%)
 * Total Accepted:    4K
 * Total Submissions: 6.5K
 * Testcase Example:  '"loveleetcode"\n"e"'
 *
 * 给定一个字符串 S 和一个字符 C。返回一个代表字符串 S 中每个字符到字符串 S 中的字符 C 的最短距离的数组。
 * 
 * 示例 1:
 * 
 * 
 * 输入: S = "loveleetcode", C = 'e'
 * 输出: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
 * 
 * 
 * 说明:
 * 
 * 
 * 字符串 S 的长度范围为 [1, 10000]。
 * C 是一个单字符，且保证是字符串 S 里的字符。
 * S 和 C 中的所有字母均为小写字母。
 * 
 * 
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define min(x,y) (((x) > (y)) ? (y) : (x))
#define MAXLEN 10001

int leftDistance(char* S, int len, char C, int index)
{
    for (int i = index - 1; i >=0; i--)
    {
        if (S[i] == C) return (index - i);
    }
    
    return MAXLEN;
}

int rightDistance(char* S, int len, char C, int index)
{
    for (int i = index + 1; i < len; i++)
    {
        if (S[i] == C) return (i - index);
    }
    
    return MAXLEN;
}


int* shortestToChar(char* S, char C, int* returnSize) {
    if(S == NULL) return NULL;
    int len = strlen(S);
    
    int* res = (int*)malloc(sizeof(int) * len);
    memset(res, 0, sizeof(int) * len);
    *returnSize = len;

    
    for (int i = 0; i < len; i++)
    {
        if (S[i] == C) continue;
        int left = leftDistance(S, len, C, i);
        int right = rightDistance(S, len, C, i);
        res[i] = min(left, right);
    }   
    
    return res;
}
