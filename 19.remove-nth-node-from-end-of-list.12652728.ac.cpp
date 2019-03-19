/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
 *
 * https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (32.21%)
 * Total Accepted:    30.2K
 * Total Submissions: 93.7K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
 * 
 * 示例：
 * 
 * 给定一个链表: 1->2->3->4->5, 和 n = 2.
 * 
 * 当删除了倒数第二个节点后，链表变为 1->2->3->5.
 * 
 * 
 * 说明：
 * 
 * 给定的 n 保证是有效的。
 * 
 * 进阶：
 * 
 * 你能尝试使用一趟扫描实现吗？
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i = 1;
        ListNode* p1 = head;
        while (i < n && p1)
        {
            p1 = p1->next;
            i++;
        }
        
        // now p1 at the first nth node;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* p2 = &dummy;
        while(p1->next)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        
        // now p1 is at the tail of the list, remove p2's next node;
        struct ListNode* temp = p2->next;
        if (temp == NULL) return head;
        
        p2->next = temp->next;
        delete temp;
        return dummy.next;
    }
};
