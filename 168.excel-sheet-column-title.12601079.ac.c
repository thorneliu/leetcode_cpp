/*
 * @lc app=leetcode.cn id=168 lang=c
 *
 * [168] Excel表列名称
 *
 * https://leetcode-cn.com/problems/excel-sheet-column-title/description/
 *
 * algorithms
 * Easy (29.91%)
 * Total Accepted:    5.2K
 * Total Submissions: 17.4K
 * Testcase Example:  '1'
 *
 * 给定一个正整数，返回它在 Excel 表中相对应的列名称。
 * 
 * 例如，
 * 
 * ⁠   1 -> A
 * ⁠   2 -> B
 * ⁠   3 -> C
 * ⁠   ...
 * ⁠   26 -> Z
 * ⁠   27 -> AA
 * ⁠   28 -> AB 
 * ⁠   ...
 * 
 * 
 * 示例 1:
 * 
 * 输入: 1
 * 输出: "A"
 * 
 * 
 * 示例 2:
 * 
 * 输入: 28
 * 输出: "AB"
 * 
 * 
 * 示例 3:
 * 
 * 输入: 701
 * 输出: "ZY"
 * 
 * 
 */
// This is a 26 weighted digitial system
char* convertToTitle(int n) {
    int result[10] = {0};
    int cnt = 0;
    while (n != 0)
    {
        result[cnt++] = (n-1) % 26;
        n = (n-1)/26;
    }
        
    // NOW we have to convert this array to ALPHABETAS
    char *p = (char *)malloc(sizeof(char) * cnt);
    for(int i = 0; i < cnt; i++)
    {
        int c =  result[i];
        p[cnt - i - 1] =  'A' + c;
    }
    
    return p;
}
