/*
 * @lc app=leetcode.cn id=387 lang=c
 *
 * [387] 字符串中的第一个唯一字符
 *
 * https://leetcode-cn.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (35.79%)
 * Total Accepted:    21K
 * Total Submissions: 58.8K
 * Testcase Example:  '"leetcode"'
 *
 * 给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
 * 
 * 案例:
 * 
 * 
 * s = "leetcode"
 * 返回 0.
 * 
 * s = "loveleetcode",
 * 返回 2.
 * 
 * 
 * 
 * 
 * 注意事项：您可以假定该字符串只包含小写字母。
 * 
 */
int firstUniqChar(char* s) {
    int map[26] = {0};
    int len = strlen(s);
    
    for (int i = 0; i < len; i++)
    {
        map[s[i] - 'a']++;
    }
    
    // find the first index with map[s[i] -'a'] == 1
    for (int i = 0; i < len; i++)
    {
        if (map[s[i] - 'a'] == 1) return i;
    }
    
    return -1;
}
