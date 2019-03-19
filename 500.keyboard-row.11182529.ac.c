/*
 * @lc app=leetcode.cn id=500 lang=c
 *
 * [500] 键盘行
 *
 * https://leetcode-cn.com/problems/keyboard-row/description/
 *
 * algorithms
 * Easy (64.59%)
 * Total Accepted:    5.3K
 * Total Submissions: 8.3K
 * Testcase Example:  '["Hello","Alaska","Dad","Peace"]'
 *
 * 给定一个单词列表，只返回可以使用在键盘同一行的字母打印出来的单词。键盘如下图所示。
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 输入: ["Hello", "Alaska", "Dad", "Peace"]
 * 输出: ["Alaska", "Dad"]
 * 
 * 
 * 
 * 
 * 注意：
 * 
 * 
 * 你可以重复使用键盘上同一字符。
 * 你可以假设输入的字符串将只包含字母。
 * 
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MAXWORDS 1000

//global lookup table
char map[255] = {0};

void initMap()
{
    map['Q'] = map['q'] = 1; map['W'] = map['w'] = 1; map['E'] = map['e'] = 1; map['R'] = map['r'] = 1; 
    map['T'] = map['t'] = 1; map['Y'] = map['y'] = 1; map['U'] = map['u'] = 1; map['I'] = map['i'] = 1; 
    map['O'] = map['o'] = 1; map['P'] = map['p'] = 1;

    map['A'] = map['a'] = 2; map['S'] = map['s'] = 2; map['D'] = map['d'] = 2; map['F'] = map['f'] = 2;
    map['G'] = map['g'] = 2; map['H'] = map['h'] = 2; map['J'] = map['j'] = 2; map['K'] = map['k'] = 2;
    map['L'] = map['l'] = 2;

    map['Z'] = map['z'] = 3; map['X'] = map['x'] = 3; map['C'] = map['c'] = 3; map['V'] = map['v'] = 3;
    map['B'] = map['b'] = 3; map['N'] = map['n'] = 3; map['M'] = map['m'] = 3; 
    
    return 0;
}

bool isInKeyboardRow(char* str)
{
    int len = strlen(str);
    if (len <= 1) return true;
    
    char *p = str;
    char currentValue = map[*p];
    p++;
    while(*p != '\0')
    {
        if(map[*p] != currentValue) return false;
        p++;
    }
    
    return true;
}

char** findWords(char** words, int wordsSize, int* returnSize) {
    initMap();
    char candidateMap[MAXWORDS] = {0};
    int cnt = 0;
    for (int i = 0; i < wordsSize; i++)
    {
        if(isInKeyboardRow(words[i])) 
        {
            candidateMap[i] = 1;
            cnt++;
        }
        
    }
    
    *returnSize = cnt;
    char** p = (char **)malloc(sizeof(char*) * cnt);
    int j = 0;
    int len = 0;
    for (int i = 0; i < wordsSize; i++)
    {
        if(candidateMap[i] == 1) 
        {
            len = strlen(words[i]);
            p[j] = (char *)malloc(sizeof(char) * (len+1));
            memcpy(p[j], words[i], sizeof(char) * (len+1));
            j++;
        }
    }
    
    return p;
}
