/*
 * @lc app=leetcode.cn id=506 lang=cpp
 *
 * [506] 相对名次
 *
 * https://leetcode-cn.com/problems/relative-ranks/description/
 *
 * algorithms
 * Easy (47.69%)
 * Total Accepted:    2.3K
 * Total Submissions: 4.7K
 * Testcase Example:  '[5,4,3,2,1]'
 *
 * 给出 N 名运动员的成绩，找出他们的相对名次并授予前三名对应的奖牌。前三名运动员将会被分别授予 “金牌”，“银牌” 和“ 铜牌”（"Gold
 * Medal", "Silver Medal", "Bronze Medal"）。
 * 
 * (注：分数越高的选手，排名越靠前。)
 * 
 * 示例 1:
 * 
 * 
 * 输入: [5, 4, 3, 2, 1]
 * 输出: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
 * 解释: 前三名运动员的成绩为前三高的，因此将会分别被授予 “金牌”，“银牌”和“铜牌” ("Gold Medal", "Silver Medal"
 * and "Bronze Medal").
 * 余下的两名运动员，我们只需要通过他们的成绩计算将其相对名次即可。
 * 
 * 提示:
 * 
 * 
 * N 是一个正整数并且不会超过 10000。
 * 所有运动员的成绩都不相同。
 * 
 * 
 */
/*
 * @lc app=leetcode.cn id=506 lang=cpp
 *
 * [506] 相对名次
 *
 * https://leetcode-cn.com/problems/relative-ranks/description/
 *
 * algorithms
 * Easy (47.51%)
 * Total Accepted:    2.2K
 * Total Submissions: 4.7K
 * Testcase Example:  '[5,4,3,2,1]'
 *
 * 给出 N 名运动员的成绩，找出他们的相对名次并授予前三名对应的奖牌。前三名运动员将会被分别授予 “金牌”，“银牌” 和“ 铜牌”（"Gold
 * Medal", "Silver Medal", "Bronze Medal"）。
 * 
 * (注：分数越高的选手，排名越靠前。)
 * 
 * 示例 1:
 * 
 * 
 * 输入: [5, 4, 3, 2, 1]
 * 输出: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
 * 解释: 前三名运动员的成绩为前三高的，因此将会分别被授予 “金牌”，“银牌”和“铜牌” ("Gold Medal", "Silver Medal"
 * and "Bronze Medal").
 * 余下的两名运动员，我们只需要通过他们的成绩计算将其相对名次即可。
 * 
 * 提示:
 * 
 * 
 * N 是一个正整数并且不会超过 10000。
 * 所有运动员的成绩都不相同。
 * 
 * 
 */
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<pair<int ,int>> scoreList; // <value, index>

        for (int i = 0; i < nums.size(); i++)
        {
            scoreList.push_back({nums[i], i});
        }

        sort(scoreList.begin(), scoreList.end(), 
            [](const pair<int, int>& a, const pair<int, int>& b) {return a.first > b.first;});

        vector<pair<int, int>> indexList;
        for (int i = 0; i < scoreList.size(); i++)
        {
            indexList.push_back({i, scoreList[i].second});
        }

        sort(indexList.begin(), indexList.end(), 
            [](const pair<int, int>& a, const pair<int, int>& b) {return a.second < b.second;});
        
        vector<string> res;
        for (auto rec : indexList)
        {
            if (rec.first == 0) 
            {
                res.push_back("Gold Medal");
            }
            else if (rec.first == 1)
            {
                res.push_back("Silver Medal");
            }
            else if (rec.first == 2)
            {
                res.push_back("Bronze Medal");
            }
            else
            {
                res.push_back(to_string(rec.first + 1));
            }
        }

        return res;
    }
};


