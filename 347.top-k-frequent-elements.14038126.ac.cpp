/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前K个高频元素
 *
 * https://leetcode-cn.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (54.09%)
 * Total Accepted:    8.3K
 * Total Submissions: 15.3K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * 给定一个非空的整数数组，返回其中出现频率前 k 高的元素。
 * 
 * 示例 1:
 * 
 * 输入: nums = [1,1,1,2,2,3], k = 2
 * 输出: [1,2]
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums = [1], k = 1
 * 输出: [1]
 * 
 * 说明：
 * 
 * 
 * 你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
 * 你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。
 * 
 * 
 */
/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前K个高频元素
 *
 * https://leetcode-cn.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (53.43%)
 * Total Accepted:    7.5K
 * Total Submissions: 14K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * 给定一个非空的整数数组，返回其中出现频率前 k 高的元素。
 * 
 * 示例 1:
 * 
 * 输入: nums = [1,1,1,2,2,3], k = 2
 * 输出: [1,2]
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums = [1], k = 1
 * 输出: [1]
 * 
 * 说明：
 * 
 * 
 * 你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
 * 你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。
 * 
 * 
 */
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> eleCnt_;
        for (const auto ele : nums)
        {
            if (eleCnt_.find(ele) == eleCnt_.end())
            {
                eleCnt_.insert({ele, 1});
            }
            else
            {
                eleCnt_[ele]++;
            }
        }

        priority_queue<record, vector<record>, comparator> heap;
        for (const auto &record : eleCnt_)
        {
            heap.push(record);
        }

        vector<int> res;
        int cnt = 0;
        while(cnt < k)
        {
            res.push_back(heap.top().first);
            heap.pop();
            cnt++;
        }

        return res;
    }
private:
    using record = pair<int, int>;
    class comparator{
    public:
        bool operator()(const record& a, const record& b)
        {
            return a.second < b.second;
        }
    };
};


