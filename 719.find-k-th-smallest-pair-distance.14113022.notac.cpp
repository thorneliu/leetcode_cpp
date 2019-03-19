/*
 * @lc app=leetcode.cn id=719 lang=cpp
 *
 * [719] 找出第 k 小的距离对
 *
 * https://leetcode-cn.com/problems/find-k-th-smallest-pair-distance/description/
 *
 * algorithms
 * Hard (27.61%)
 * Total Accepted:    682
 * Total Submissions: 2.5K
 * Testcase Example:  '[1,3,1]\n1'
 *
 * 给定一个整数数组，返回所有数对之间的第 k 个最小距离。一对 (A, B) 的距离被定义为 A 和 B 之间的绝对差值。
 * 
 * 示例 1:
 * 
 * 
 * 输入：
 * nums = [1,3,1]
 * k = 1
 * 输出：0 
 * 解释：
 * 所有数对如下：
 * (1,3) -> 2
 * (1,1) -> 0
 * (3,1) -> 2
 * 因此第 1 个最小距离的数对是 (1,1)，它们之间的距离为 0。
 * 
 * 
 * 提示:
 * 
 * 
 * 2 <= len(nums) <= 10000.
 * 0 <= nums[i] < 1000000.
 * 1 <= k <= len(nums) * (len(nums) - 1) / 2.
 * 
 * 
 */
/*
 * @lc app=leetcode.cn id=719 lang=cpp
 *
 * [719] 找出第 k 小的距离对
 *
 * https://leetcode-cn.com/problems/find-k-th-smallest-pair-distance/description/
 *
 * algorithms
 * Hard (27.32%)
 * Total Accepted:    656
 * Total Submissions: 2.4K
 * Testcase Example:  '[1,3,1]\n1'
 *
 * 给定一个整数数组，返回所有数对之间的第 k 个最小距离。一对 (A, B) 的距离被定义为 A 和 B 之间的绝对差值。
 * 
 * 示例 1:
 * 
 * 
 * 输入：
 * nums = [1,3,1]
 * k = 1
 * 输出：0 
 * 解释：
 * 所有数对如下：
 * (1,3) -> 2
 * (1,1) -> 0
 * (3,1) -> 2
 * 因此第 1 个最小距离的数对是 (1,1)，它们之间的距离为 0。
 * 
 * 
 * 提示:
 * 
 * 
 * 2 <= len(nums) <= 10000.
 * 0 <= nums[i] < 1000000.
 * 1 <= k <= len(nums) * (len(nums) - 1) / 2.
 * 
 * 
 */
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        auto size = nums.size();
        int Cnt = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> heap;

        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (Cnt < k)
                {
                    heap.push({nums[i], nums[j]});
                }
                else
                {
                    auto d = abs(nums[i] - nums[j]);
                    auto top = heap.top();
                    if (d < abs(top.first - top.second))
                    {
                        heap.pop();
                        heap.push({nums[i], nums[j]});
                    }    
                }

                Cnt++;
            }
        }

        auto top = heap.top();
        return abs(top.first - top.second);
    }
private:
    struct cmp{
        bool operator() (const pair<int,int>& a, const pair<int, int>& b)
        {
            auto d1 = abs(a.first - a.second);
            auto d2 = abs(b.first - b.second);
            return d1 < d2;
        }
    };
};


