/*
 * @lc app=leetcode.cn id=744 lang=c
 *
 * [744] 网络延迟时间
 *
 * https://leetcode-cn.com/problems/find-smallest-letter-greater-than-target/description/
 *
 * algorithms
 * Easy (41.41%)
 * Total Accepted:    3.1K
 * Total Submissions: 7.5K
 * Testcase Example:  '["c","f","j"]\n"a"'
 *
 * 给定一个只包含小写字母的有序数组letters 和一个目标字母 target，寻找有序数组里面比目标字母大的最小字母。
 * 
 * 数组里字母的顺序是循环的。举个例子，如果目标字母target = 'z' 并且有序数组为 letters = ['a', 'b']，则答案返回
 * 'a'。
 * 
 * 示例:
 * 
 * 
 * 输入:
 * letters = ["c", "f", "j"]
 * target = "a"
 * 输出: "c"
 * 
 * 输入:
 * letters = ["c", "f", "j"]
 * target = "c"
 * 输出: "f"
 * 
 * 输入:
 * letters = ["c", "f", "j"]
 * target = "d"
 * 输出: "f"
 * 
 * 输入:
 * letters = ["c", "f", "j"]
 * target = "g"
 * 输出: "j"
 * 
 * 输入:
 * letters = ["c", "f", "j"]
 * target = "j"
 * 输出: "c"
 * 
 * 输入:
 * letters = ["c", "f", "j"]
 * target = "k"
 * 输出: "c"
 * 
 * 
 * 注:
 * 
 * 
 * letters长度范围在[2, 10000]区间内。
 * letters 仅由小写字母组成，最少包含两个不同的字母。
 * 目标字母target 是一个小写字母。
 * 
 * 
 */
char nextGreatestLetter(char* letters, int lettersSize, char target) {
    char candidate = 0;
    int l = 0;
    int h = lettersSize;
    int m = 0;
    while(l < h)
    {
        m = l + (h - l)/2;
        if (letters[m] <= target)
        {
            l = m + 1;
        }
        else
        {
            h = m;
        }
    }

    return letters[l % lettersSize];
}
