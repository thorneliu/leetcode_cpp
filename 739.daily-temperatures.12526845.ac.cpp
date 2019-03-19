/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 *
 * https://leetcode-cn.com/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (57.47%)
 * Total Accepted:    3.3K
 * Total Submissions: 5.7K
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 * 根据每日 气温 列表，请重新生成一个列表，对应位置的输入是你需要再等待多久温度才会升高的天数。如果之后都不会升高，请输入 0 来代替。
 * 
 * 例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4,
 * 2, 1, 1, 0, 0]。
 * 
 * 提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的都是 [30, 100] 范围内的整数。
 * 
 */
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size() ; 
        vector<int> result(n,0); 
        stack<int> st;

        for( int i = 0 ; i < n ; i++ )
        {
            while(!st.empty() && T[st.top()] < T[i] )
            {
                result[st.top()] = i-st.top() ; 
                st.pop() ;
            }

            st.push(i);
        }

        return result ; 
    }
};
