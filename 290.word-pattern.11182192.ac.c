/*
 * @lc app=leetcode.cn id=290 lang=c
 *
 * [290] 单词模式
 *
 * https://leetcode-cn.com/problems/word-pattern/description/
 *
 * algorithms
 * Easy (37.22%)
 * Total Accepted:    4.8K
 * Total Submissions: 12.8K
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * 给定一种 pattern(模式) 和一个字符串 str ，判断 str 是否遵循相同的模式。
 * 
 * 这里的遵循指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应模式。
 * 
 * 示例1:
 * 
 * 输入: pattern = "abba", str = "dog cat cat dog"
 * 输出: true
 * 
 * 示例 2:
 * 
 * 输入:pattern = "abba", str = "dog cat cat fish"
 * 输出: false
 * 
 * 示例 3:
 * 
 * 输入: pattern = "aaaa", str = "dog cat cat dog"
 * 输出: false
 * 
 * 示例 4:
 * 
 * 输入: pattern = "abba", str = "dog dog dog dog"
 * 输出: false
 * 
 * 说明:
 * 你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。    
 * 
 */
#define NUM_OF_LETTERS (26)

bool isSameStr(char* s1, char* s2)
{
    if(s1 == NULL || s2 == NULL) return false;
    
    char* p1;
    char* p2;
    p1 = s1;
    p2 = s2;
    
    while(*p1 != '\0' && *p2 != '\0')
    {
        if(*p1 != *p2) break;
        p1++;
        p2++;
    }
    
    //printf("*p1 = %c, *p2 = %c\n", *p1, *p2);
    if(*p1 != '\0' || *p2 != '\0') return false;
    
    return true;
}

bool wordPattern(char* pattern, char* str) {
    if(pattern == NULL || str == NULL) return false;
    
    char* map[NUM_OF_LETTERS] = {0};
    char* p = pattern;
    char* s = str;
    int i = 0;
    int j = 0;
    bool bsameStr = false;
    
    while(*p != '\0' && *s != '\0')
    {
        i = 0;
        char *word_begin = s;
        
        while(*s != ' ' && *s !='\0')
        {
            s++;
            i++;
        }
        
        char *word = (char *)malloc((i + 1)*sizeof(char));
        memcpy(word, word_begin, i*sizeof(char));
        *(word+i) = '\0';
        
        for(j = 0; j < NUM_OF_LETTERS; j++)
        {
            if(isSameStr(word, map[j])) break;
        }
        
        if(j != NUM_OF_LETTERS && map[*p - 'a'] == NULL)
        {
            printf("word %s alreay mapped to %c, So %c could not map it again\n", word, (j+'a'), *p);
            free(word);
            break;
        }
        
        if(map[*p - 'a'] == NULL)
        {
            printf("map[%c] = %s\n", *p, word);
            map[*p - 'a'] = word;
        }
        else
        {
            bsameStr = isSameStr(word, map[*p - 'a']);
            printf("isSameStr %s, %s --> %s\n", word, map[*p - 'a'], bsameStr?"Y":"N");
            free(word);
            if(!bsameStr) break;
        }
        
        p++;
        if(*s != '\0') s++;
    }
    
    for(i = 0;  i < NUM_OF_LETTERS; i++)
    {
        if(map[i] != NULL) free(map[i]);
    }
    
    if(*p != '\0' || *s != '\0') return false;
    
    return true;
}
