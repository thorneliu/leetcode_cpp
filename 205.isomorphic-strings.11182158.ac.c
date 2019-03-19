/*
 * @lc app=leetcode.cn id=205 lang=c
 *
 * [205] 同构字符串
 *
 * https://leetcode-cn.com/problems/isomorphic-strings/description/
 *
 * algorithms
 * Easy (42.81%)
 * Total Accepted:    7.1K
 * Total Submissions: 16.6K
 * Testcase Example:  '"egg"\n"add"'
 *
 * 给定两个字符串 s 和 t，判断它们是否是同构的。
 * 
 * 如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。
 * 
 * 所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。
 * 
 * 示例 1:
 * 
 * 输入: s = "egg", t = "add"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: s = "foo", t = "bar"
 * 输出: false
 * 
 * 示例 3:
 * 
 * 输入: s = "paper", t = "title"
 * 输出: true
 * 
 * 说明:
 * 你可以假设 s 和 t 具有相同的长度。
 * 
 */
#define NUM_OF_CHAR (128)

bool isIsomorphic(char* s, char* t) {
    if(s == NULL || t == NULL) return false;
    
    int  offset[NUM_OF_CHAR] = {0};
    int i;
    for (i = 0; i < NUM_OF_CHAR; i++)
        offset[i] = -1;
    
    char map[NUM_OF_CHAR] = {0};
    
    char *ps = s;
    char *pt = t;
    
    while(*ps != '\0' && *pt != '\0')
    {
        if(offset[*ps] == -1)
            offset[*ps] = *pt - *ps;
        else
            {if(*ps + offset[*ps] != *pt) break;}
        
        if(map[*pt] == 0)
            map[*pt] = *ps;
        else
            {if(map[*pt] != *ps) break;}
        
        ps++;
        pt++;
    }
    
    if(*ps != '\0' || *pt != '\0') 
        return false;
    else 
        return true;
}
