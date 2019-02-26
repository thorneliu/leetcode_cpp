/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 *
 * https://leetcode-cn.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (44.49%)
 * Total Accepted:    4.9K
 * Total Submissions: 11.1K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * 给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
 * 
 * 你应当保留两个分区中每个节点的初始相对位置。
 * 
 * 示例:
 * 
 * 输入: head = 1->4->3->2->5->2, x = 3
 * 输出: 1->2->2->4->3->5
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
    ListNode* partition(ListNode* head, int x) {
        if (!head) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* p1 = &dummy;

        while(p1 && p1->next && p1->next->val < x) p1 = p1->next;
        if (!p1 || !p1->next) return dummy.next;

        ListNode* p2 = p1->next;
        ListNode* p2prev = p1;
        while(p2)
        {
            while(p2 && p2->val >= x)
            {
                p2 = p2->next;
                p2prev = p2;
            }
            if (!p2) return dummy.next;

            // move this small node after p1 and update p1
            ListNode* pX = p1->next;
            p2prev->next = p2->next;    
            p1->next = p2;
            p2->next = pX;
            
            p1 = p1->next;
            p2 = p2prev->next;
        }

        return dummy.next;
    }
};

