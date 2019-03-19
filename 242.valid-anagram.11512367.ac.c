/*
 * @lc app=leetcode.cn id=242 lang=c
 *
 * [242] 有效的字母异位词
 *
 * https://leetcode-cn.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (50.33%)
 * Total Accepted:    20.4K
 * Total Submissions: 40.5K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的一个字母异位词。
 * 
 * 示例 1:
 * 
 * 输入: s = "anagram", t = "nagaram"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: s = "rat", t = "car"
 * 输出: false
 * 
 * 说明:
 * 你可以假设字符串只包含小写字母。
 * 
 * 进阶:
 * 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
 * 
 */
bool isAnagram(char* s, char* t) {
    int lens = strlen(s);
    int lent = strlen(t);
    if (lens != lent) return false;
    
    int maps[26] = {0};
    int mapt[26] = {0};    
    for (int i = 0; i < lens; i++)
    {
        maps[s[i] - 'a']++;
        mapt[t[i] - 'a']++;
    }
    
    for (int i = 0; i < 26; i++)
    {
        if (maps[i] != mapt[i]) return false;
    }
    
    return true;
}
