/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 *
 * https://leetcode-cn.com/problems/largest-number/description/
 *
 * algorithms
 * Medium (30.86%)
 * Total Accepted:    4.8K
 * Total Submissions: 15.4K
 * Testcase Example:  '[10,2]'
 *
 * 给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。
 * 
 * 示例 1:
 * 
 * 输入: [10,2]
 * 输出: 210
 * 
 * 示例 2:
 * 
 * 输入: [3,30,34,5,9]
 * 输出: 9534330
 * 
 * 说明: 输出结果可能非常大，所以你需要返回一个字符串而不是整数。
 * 
 */
/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 *
 * https://leetcode-cn.com/problems/largest-number/description/
 *
 * algorithms
 * Medium (30.28%)
 * Total Accepted:    4.2K
 * Total Submissions: 13.7K
 * Testcase Example:  '[10,2]'
 *
 * 给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。
 * 
 * 示例 1:
 * 
 * 输入: [10,2]
 * 输出: 210
 * 
 * 示例 2:
 * 
 * 输入: [3,30,34,5,9]
 * 输出: 9534330
 * 
 * 说明: 输出结果可能非常大，所以你需要返回一个字符串而不是整数。
 * 
 */
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [this](int a, int b){
            int sizea = getDigitCnt(a);
            int sizeb = getDigitCnt(b);

            return (a * pow(10, sizeb) + b) > (b * pow(10, sizea) + a);
        });

        if (nums[0] == 0) return "0";

        ostringstream oss;
        for (auto num : nums) oss << num;
        return oss.str();
    }

private:
    int getDigitCnt(int n)
    {
        if (0 == n) return 1;

        int res = 0;
        while(n)
        {
            res++;
            n /= 10;
        }

        return res;
    }
};


