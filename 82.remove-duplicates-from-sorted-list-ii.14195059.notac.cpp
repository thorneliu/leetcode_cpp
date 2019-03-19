/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
 *
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (39.02%)
 * Total Accepted:    7.2K
 * Total Submissions: 18.5K
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * 给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。
 * 
 * 示例 1:
 * 
 * 输入: 1->2->3->3->4->4->5
 * 输出: 1->2->5
 * 
 * 
 * 示例 2:
 * 
 * 输入: 1->1->1->2->3
 * 输出: 2->3
 * 
 */
/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
 *
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (38.58%)
 * Total Accepted:    6.8K
 * Total Submissions: 17.5K
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * 给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。
 * 
 * 示例 1:
 * 
 * 输入: 1->2->3->3->4->4->5
 * 输出: 1->2->5
 * 
 * 
 * 示例 2:
 * 
 * 输入: 1->1->1->2->3
 * 输出: 2->3
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return nullptr;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* pAnchor = &dummy;

        ListNode *p1, *p2, *p;
        p = p1 = p2 = head;
        int curVal = p->val;

        while(p->next)
        {
            if (p->next->val == curVal)
            {
                p2 = p->next;
            }
            else
            {
                if (p1 == p2)
                {
                    // one unqie node
                    pAnchor = p1;
                }
                else
                {
                    // remove all nodes between [p1, p2], pAnchor stay still
                    pAnchor->next = p2->next;
                    /*
                    ListNode* pDel = p1;
                    while(pDel != p2->next)
                    {
                        ListNode* pNext = pDel->next;
                        delete pDel;
                        pDel = pNext;
                    }
                    */
                }

                curVal = p->next->val;
                p1 = p2 = p->next;
            }

            p = p->next;
        }

        pAnchor->next = p2->next;
        return dummy.next;
    }
};


