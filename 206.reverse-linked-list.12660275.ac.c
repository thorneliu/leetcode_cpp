/*
 * @lc app=leetcode.cn id=206 lang=c
 *
 * [206] 反转链表
 *
 * https://leetcode-cn.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (58.05%)
 * Total Accepted:    35.6K
 * Total Submissions: 61.2K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 反转一个单链表。
 * 
 * 示例:
 * 
 * 输入: 1->2->3->4->5->NULL
 * 输出: 5->4->3->2->1->NULL
 * 
 * 进阶:
 * 你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if (!head) return NULL;
    struct ListNode* newHead = head;
    while(head->next)
    {
        struct ListNode* p = head->next;
        head->next = p->next;
        p->next = newHead;
        newHead = p;
    }
    
    return newHead;
}
