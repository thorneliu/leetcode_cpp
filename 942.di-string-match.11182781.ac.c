/*
 * @lc app=leetcode.cn id=942 lang=c
 *
 * [942] 超级回文数
 *
 * https://leetcode-cn.com/problems/di-string-match/description/
 *
 * algorithms
 * Easy (71.35%)
 * Total Accepted:    2.8K
 * Total Submissions: 3.9K
 * Testcase Example:  '"IDID"'
 *
 * 给定只含 "I"（增大）或 "D"（减小）的字符串 S ，令 N = S.length。
 * 
 * 返回 [0, 1, ..., N] 的任意排列 A 使得对于所有 i = 0, ..., N-1，都有：
 * 
 * 
 * 如果 S[i] == "I"，那么 A[i] < A[i+1]
 * 如果 S[i] == "D"，那么 A[i] > A[i+1]
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输出："IDID"
 * 输出：[0,4,1,3,2]
 * 
 * 
 * 示例 2：
 * 
 * 输出："III"
 * 输出：[0,1,2,3]
 * 
 * 
 * 示例 3：
 * 
 * 输出："DDI"
 * 输出：[3,2,0,1]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= S.length <= 1000
 * S 只包含字符 "I" 或 "D"。
 * 
 * 
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* diStringMatch(char* S, int* returnSize) {
    if (S == NULL) return NULL;
    int len = strlen(S);
    int *res = (int *)malloc(sizeof(int) * (len+1));
    memset(res, 0, sizeof(int) * (len+1));
    int *pi = res;
    int min = 0; int max = len;
    
    char* p = S;
    while(*p != '\0')
    {
        if (*p == 'I')
        {
            *pi = min;
            min = min+1;
            pi++;
        }
        else
        {
            *pi = max;
            max = max-1;
            pi++;
        }
        
        p++;
    }
    
    if(--p == 'I')
    {
        *pi = max;
    }
    else
    {
        *pi = min;
    }
    
    *returnSize = len + 1;
    return res;
}
