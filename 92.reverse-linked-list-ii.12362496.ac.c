/*
 * @lc app=leetcode.cn id=92 lang=c
 *
 * [92] 反转链表 II
 *
 * https://leetcode-cn.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (41.43%)
 * Total Accepted:    6.5K
 * Total Submissions: 15.6K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * 反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
 * 
 * 说明:
 * 1 ≤ m ≤ n ≤ 链表长度。
 * 
 * 示例:
 * 
 * 输入: 1->2->3->4->5->NULL, m = 2, n = 4
 * 输出: 1->4->3->2->5->NULL
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    if (!head || m >= n) return head;
    struct ListNode dummy;
    dummy.next = head;
    
    int i = 1;
    struct ListNode* pNode = head;
    struct ListNode* pStartAnchor = &dummy;
    while (i < m)
    {
        pStartAnchor = pNode;
        pNode = pNode->next;
        i++;
    }
        
    struct ListNode* pm = pNode;
    pNode = pNode->next;
    i++;
    
    for (; i <= n; i++)
    {
        struct ListNode* pNext = pNode->next;
        pm->next = pNext;
        pNode->next = pStartAnchor->next;
        pStartAnchor->next = pNode;
        
        pNode = pNext;
    }
    
    return dummy.next;
}
