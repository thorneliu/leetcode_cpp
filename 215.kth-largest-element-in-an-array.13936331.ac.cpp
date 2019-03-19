/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 *
 * https://leetcode-cn.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (56.54%)
 * Total Accepted:    17.5K
 * Total Submissions: 30.9K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * 在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 * 
 * 示例 1:
 * 
 * 输入: [3,2,1,5,6,4] 和 k = 2
 * 输出: 5
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
 * 输出: 4
 * 
 * 说明: 
 * 
 * 你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。
 * 
 */
/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 *
 * https://leetcode-cn.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (56.36%)
 * Total Accepted:    15.4K
 * Total Submissions: 27.4K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * 在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 * 
 * 示例 1:
 * 
 * 输入: [3,2,1,5,6,4] 和 k = 2
 * 输出: 5
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
 * 输出: 4
 * 
 * 说明: 
 * 
 * 你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。
 * 
 */

/*
* std::priority_queue
* template <class T, class Container = vector<T>,
* class Compare = less<typename Container::value_type> > class priority_queue;
* Priority queue
* Priority queues are a type of container adaptors, specifically designed such that its first element is always the greatest of the elements it contains, according to some strict weak ordering criterion.

* This context is similar to a heap, where elements can be inserted at any moment, and only the max heap element can be retrieved (the one at the top in the priority queue).

* Priority queues are implemented as container adaptors, which are classes that use an encapsulated object of a specific container class as its underlying container, providing a specific set of member functions to access its elements. Elements are popped from the "back" of the specific container, which is known as the top of the priority queue.

* The underlying container may be any of the standard container class templates or some other specifically designed container class. The container shall be accessible through random access iterators and support the following operations:
* empty()
* size()
* front()
* push_back()
* pop_back()
*
*  std::priority_queue<int, vector<int>, less<int>> : max_heap;
*  std::priority_queue<int, vector<int>, greater<int>> : min_heap;
*  
* Member functions:
* (constructor) Construct priority queue (public member function )
* empty          Test whether container is empty (public member function )
* size           Return size (public member function )
* top            Access top element (public member function )
* push           Insert element (public member function )
* emplace        Construct and insert element (public member function )
* pop            Remove top element (public member function )
* swap           Swap contents (public member function )
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minheap(nums.begin(), nums.begin() + k);
        for (int i = k; i < nums.size(); i++)
        {
            auto ele = nums[i];
            if (ele > minheap.top())
            {
                minheap.pop();
                minheap.push(ele);
            }
        }

        return minheap.top();   
    }
};


