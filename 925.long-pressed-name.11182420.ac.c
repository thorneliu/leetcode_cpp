/*
 * @lc app=leetcode.cn id=925 lang=c
 *
 * [925] 根据前序和后序遍历构造二叉树
 *
 * https://leetcode-cn.com/problems/long-pressed-name/description/
 *
 * algorithms
 * Easy (40.28%)
 * Total Accepted:    1.7K
 * Total Submissions: 4.2K
 * Testcase Example:  '"alex"\n"aaleex"'
 *
 * 你的朋友正在使用键盘输入他的名字 name。偶尔，在键入字符 c 时，按键可能会被长按，而字符可能被输入 1 次或多次。
 * 
 * 你将会检查键盘输入的字符 typed。如果它对应的可能是你的朋友的名字（其中一些字符可能被长按），那么就返回 True。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：name = "alex", typed = "aaleex"
 * 输出：true
 * 解释：'alex' 中的 'a' 和 'e' 被长按。
 * 
 * 
 * 示例 2：
 * 
 * 输入：name = "saeed", typed = "ssaaedd"
 * 输出：false
 * 解释：'e' 一定需要被键入两次，但在 typed 的输出中不是这样。
 * 
 * 
 * 示例 3：
 * 
 * 输入：name = "leelee", typed = "lleeelee"
 * 输出：true
 * 
 * 
 * 示例 4：
 * 
 * 输入：name = "laiden", typed = "laiden"
 * 输出：true
 * 解释：长按名字中的字符并不是必要的。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * name.length <= 1000
 * typed.length <= 1000
 * name 和 typed 的字符都是小写字母。
 * 
 * 
 * 
 * 
 * 
 * 
 */
bool isLongPressedName(char* name, char* typed) {
    if (name == NULL || typed == NULL) return false;
    
    char *p1 = name;
    char *p2 = typed;
    
    char preTyped = *p2; 
    if (*p1 != *p2) return false; // failed on the very first one.
    
    p1++;
    p2++;
    while(*p1 != '\0')
    {
        // The typed should provide p1 every char in name
        while(*p2 != *p1)
        {
            if (*p2 == preTyped)
            {
                // sorry, this is a long pressed one, Let's try next one
                //printf("LONGPRESSED!!: p2 moved form %c to %c\n", *p2, *(p2+1));
                p2++;
            }
            else
            {
                // sorry man, it is not matched
                //printf("*p1 = %c, *p2 = %c\n", *p1, *p2);
                return false;
            }
        }
        
        //printf("p1 moved form %c to %c\n", *p1, *(p1+1));
        p1++;
        //printf("p2 moved form %c to %c\n", *p2, *(p2+1));
        preTyped = *p2;
        p2++;
    }
    
    return true;
}
