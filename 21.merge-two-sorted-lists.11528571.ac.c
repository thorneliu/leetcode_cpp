/*
 * @lc app=leetcode.cn id=21 lang=c
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (52.56%)
 * Total Accepted:    44.7K
 * Total Submissions: 85K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * 示例：
 * 
 * 输入：1->2->4, 1->3->4
 * 输出：1->1->2->3->4->4
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if(l1 == NULL && l2 == NULL) return NULL;
    if(l1 == NULL || l2 == NULL) return l1 ? l1 : l2;
    if(l1->val > l2->val)
    {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
    else
    {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
}
