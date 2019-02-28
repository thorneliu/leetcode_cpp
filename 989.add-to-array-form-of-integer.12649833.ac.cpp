/*
 * @lc app=leetcode.cn id=989 lang=cpp
 *
 * [989] 按公因数计算最大组件大小
 *
 * https://leetcode-cn.com/problems/add-to-array-form-of-integer/description/
 *
 * algorithms
 * Easy (41.16%)
 * Total Accepted:    992
 * Total Submissions: 2.4K
 * Testcase Example:  '[1,2,0,0]\n34'
 *
 * 对于非负整数 X 而言，X 的数组形式是每位数字按从左到右的顺序形成的数组。例如，如果 X = 1231，那么其数组形式为 [1,2,3,1]。
 * 
 * 给定非负整数 X 的数组形式 A，返回整数 X+K 的数组形式。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：A = [1,2,0,0], K = 34
 * 输出：[1,2,3,4]
 * 解释：1200 + 34 = 1234
 * 
 * 
 * 解释 2：
 * 
 * 输入：A = [2,7,4], K = 181
 * 输出：[4,5,5]
 * 解释：274 + 181 = 455
 * 
 * 
 * 示例 3：
 * 
 * 输入：A = [2,1,5], K = 806
 * 输出：[1,0,2,1]
 * 解释：215 + 806 = 1021
 * 
 * 
 * 示例 4：
 * 
 * 输入：A = [9,9,9,9,9,9,9,9,9,9], K = 1
 * 输出：[1,0,0,0,0,0,0,0,0,0,0]
 * 解释：9999999999 + 1 = 10000000000
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= A.length <= 10000
 * 0 <= A[i] <= 9
 * 0 <= K <= 10000
 * 如果 A.length > 1，那么 A[0] != 0
 * 
 * 
 */
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> res;
        reverse(A.begin(), A.end());
        auto len1 = A.size();
        auto kVec = convertNumber2Aarry(K);
        auto len2 = kVec.size();
        
        int i = 0; 
        int j = 0;
        bool carry = false;
        
        while (i < len1 || j < len2)
        {
            auto op1 = (i == len1) ? 0 : A[i];
            auto op2 = (j == len2) ? 0 : kVec[j];
            
            auto sum = op1 + op2 + (carry ? 1 : 0);
            res.push_back(sum % 10);
            carry = sum >= 10;
            
            if (i < len1) i++;
            if (j < len2) j++;
        }
        
        if (carry) res.push_back(1);
        reverse(res.begin(), res.end());
        
        return res;
    }
    
private:
    vector<int> convertNumber2Aarry(int K)
    {
        vector<int> res;
        while(K)
        {
            res.push_back(K % 10);
            K = K / 10;
        }
        
        return res;
    }
};
