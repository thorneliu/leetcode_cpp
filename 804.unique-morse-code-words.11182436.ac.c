/*
 * @lc app=leetcode.cn id=804 lang=c
 *
 * [804] 旋转数字
 *
 * https://leetcode-cn.com/problems/unique-morse-code-words/description/
 *
 * algorithms
 * Easy (69.57%)
 * Total Accepted:    7.8K
 * Total Submissions: 11.2K
 * Testcase Example:  '["gin", "zen", "gig", "msg"]'
 *
 * 国际摩尔斯密码定义一种标准编码方式，将每个字母对应于一个由一系列点和短线组成的字符串， 比如: "a" 对应 ".-", "b" 对应 "-...",
 * "c" 对应 "-.-.", 等等。
 * 
 * 为了方便，所有26个英文字母对应摩尔斯密码表如下：
 * 
 * 
 * [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
 * 
 * 给定一个单词列表，每个单词可以写成每个字母对应摩尔斯密码的组合。例如，"cab" 可以写成 "-.-..--..."，(即 "-.-." +
 * "-..." + ".-"字符串的结合)。我们将这样一个连接过程称作单词翻译。
 * 
 * 返回我们可以获得所有词不同单词翻译的数量。
 * 
 * 例如:
 * 输入: words = ["gin", "zen", "gig", "msg"]
 * 输出: 2
 * 解释: 
 * 各单词翻译如下:
 * "gin" -> "--...-."
 * "zen" -> "--...-."
 * "gig" -> "--...--."
 * "msg" -> "--...--."
 * 
 * 共有 2 种不同翻译, "--...-." 和 "--...--.".
 * 
 * 
 * 
 * 
 * 注意:
 * 
 * 
 * 单词列表words 的长度不会超过 100。
 * 每个单词 words[i]的长度范围为 [1, 12]。
 * 每个单词 words[i]只包含小写字母。
 * 
 * 
 */
typedef struct {
    char len;
    char val;
} morseCode;

morseCode codeTable[] = {
    {2, 2}, /* a .-   10*/
    {4, 7}, /* b -... 0111*/
    {4, 5}, /* c -.-. 0101 */
    {3, 3},
    {1, 1},
    {4,13},
    {3, 1},
    {4,15},
    {2, 3},
    {4, 8},
    {3, 2},
    {4,11},
    {2, 0},
    {2, 1},
    {3, 0},
    {4, 9},
    {4, 2},
    {3, 5},
    {3, 7},
    {1, 0},
    {3, 6},
    {4,14},
    {3, 4},
    {4, 6},
    {4, 4},
    {4, 3}
};

typedef struct{
    int len;
    int val;
}morseString;

morseString getmorseString(char* s) {
    morseString str;
    str.len = 0;
    str.val = 0;
    
    char *p = s;
    while(*p != '\0')
    {
        char c = *p;
        if (c < 'a' || c > 'z'){
            printf("Invalid input *p = %c\n", c);
            p++;
            continue;
        }
        
        morseCode code = codeTable[c - 'a']; 
        //printf("%c: %d-%d\n", c, code.len, code.val);
        str.len += code.len;
        str.val = (str.val << (code.len)) + code.val;
        p++;
    }
    
    return str;
}

int uniqueMorseRepresentations(char** words, int wordsSize) {
    int result = -1;
    morseString stack[100];
    
    for(int i = 0; i < wordsSize; i++)
    {
        morseString str = getmorseString(words[i]);
        //printf("words[%d] = %s, str.len = %d, str.val = %d, result = %d\n", i, words[i], str.len, str.val, result);
        bool foundone = false;
        for (int j = 0; j <= result; j++)
        {
            // check one by one if str in stack
            if (stack[j].len == str.len && stack[j].val == str.val) {
                //printf("found one with %d-%d\n", str.len, str.val);
                foundone = true;
                break;
            }
        }
        
        if (!foundone)
        {
            //printf("NOT found one with %d-%d\n", str.len, str.val);
            result++;
            stack[result] = str;
        }
    }
    
    return result + 1;
}
