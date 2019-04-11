/*
 * @lc app=leetcode.cn id=725 lang=cpp
 *
 * [725] 分隔链表
 *
 * https://leetcode-cn.com/problems/split-linked-list-in-parts/description/
 *
 * algorithms
 * Medium (47.95%)
 * Total Accepted:    1.1K
 * Total Submissions: 2.2K
 * Testcase Example:  '[1,2,3,4]\n5'
 *
 * 给定一个头结点为 root 的链表, 编写一个函数以将链表分隔为 k 个连续的部分。
 * 
 * 每部分的长度应该尽可能的相等: 任意两部分的长度差距不能超过 1，也就是说可能有些部分为 null。
 * 
 * 这k个部分应该按照在链表中出现的顺序进行输出，并且排在前面的部分的长度应该大于或等于后面的长度。
 * 
 * 返回一个符合上述规则的链表的列表。
 * 
 * 举例： 1->2->3->4, k = 5 // 5 结果 [ [1], [2], [3], [4], null ]
 * 
 * 示例 1：
 * 
 * 
 * 输入: 
 * root = [1, 2, 3], k = 5
 * 输出: [[1],[2],[3],[],[]]
 * 解释:
 * 输入输出各部分都应该是链表，而不是数组。
 * 例如, 输入的结点 root 的 val= 1, root.next.val = 2, \root.next.next.val = 3, 且
 * root.next.next.next = null。
 * 第一个输出 output[0] 是 output[0].val = 1, output[0].next = null。
 * 最后一个元素 output[4] 为 null, 它代表了最后一个部分为空链表。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入: 
 * root = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 3
 * 输出: [[1, 2, 3, 4], [5, 6, 7], [8, 9, 10]]
 * 解释:
 * 输入被分成了几个连续的部分，并且每部分的长度相差不超过1.前面部分的长度大于等于后面部分的长度。
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * root 的长度范围： [0, 1000].
 * 输入的每个节点的大小范围：[0, 999].
 * k 的取值范围： [1, 50].
 * 
 * 
 * 
 * 
 */
/*
 * @lc app=leetcode.cn id=725 lang=cpp
 *
 * [725] 分隔链表
 *
 * https://leetcode-cn.com/problems/split-linked-list-in-parts/description/
 *
 * algorithms
 * Medium (47.95%)
 * Total Accepted:    1.1K
 * Total Submissions: 2.2K
 * Testcase Example:  '[1,2,3,4]\n5'
 *
 * 给定一个头结点为 root 的链表, 编写一个函数以将链表分隔为 k 个连续的部分。
 * 
 * 每部分的长度应该尽可能的相等: 任意两部分的长度差距不能超过 1，也就是说可能有些部分为 null。
 * 
 * 这k个部分应该按照在链表中出现的顺序进行输出，并且排在前面的部分的长度应该大于或等于后面的长度。
 * 
 * 返回一个符合上述规则的链表的列表。
 * 
 * 举例： 1->2->3->4, k = 5 // 5 结果 [ [1], [2], [3], [4], null ]
 * 
 * 示例 1：
 * 
 * 
 * 输入: 
 * root = [1, 2, 3], k = 5
 * 输出: [[1],[2],[3],[],[]]
 * 解释:
 * 输入输出各部分都应该是链表，而不是数组。
 * 例如, 输入的结点 root 的 val= 1, root.next.val = 2, \root.next.next.val = 3, 且
 * root.next.next.next = null。
 * 第一个输出 output[0] 是 output[0].val = 1, output[0].next = null。
 * 最后一个元素 output[4] 为 null, 它代表了最后一个部分为空链表。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入: 
 * root = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 3
 * 输出: [[1, 2, 3, 4], [5, 6, 7], [8, 9, 10]]
 * 解释:
 * 输入被分成了几个连续的部分，并且每部分的长度相差不超过1.前面部分的长度大于等于后面部分的长度。
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * root 的长度范围： [0, 1000].
 * 输入的每个节点的大小范围：[0, 999].
 * k 的取值范围： [1, 50].
 * 
 * 
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int size = getListLength(root);
        vector<int> sizeList(k, 0);
        int divided = k;
        int quotient = size / divided;
        int remainder = size % divided;

        while(quotient < remainder && divided > 1)
        {
            divided = divided - 1;
            quotient = size / divided;
            remainder = size % divided;
        }

        for (int i = 0; i < divided; i++) sizeList[i] = quotient;
        if (remainder == quotient - 1 && divided < k)
        {
            sizeList[divided] = remainder;
        }
        else
        {
            for (int i = 0; i < remainder; i++) sizeList[i] = sizeList[i] + 1;
        }
        

        ListNode* p = root;
        ListNode* pNext = nullptr;
        vector<ListNode*> res;
        for(int i = 0; i < k; i++)
        {
            int partiSize = sizeList[i];
            if (partiSize > 0 )
            {
                res.push_back(p);
                int j = 0;
                while(p && j < partiSize - 1)
                {
                    p = p->next;
                    j++;
                }

                if (p != nullptr)
                {
                    pNext = p->next;
                    p->next = nullptr;
                    p = pNext;
                }
            }
            else
            {
                res.push_back(nullptr);
            }
            

        }

        return res;
    }
private:
    int getListLength(ListNode* root)
    {
        int res = 0;
        ListNode* p = root;
        while(p)
        {
            res++;
            p = p->next;
        }

        //std::cout << "size = " << res << std::endl;
        return res;
    }
};


