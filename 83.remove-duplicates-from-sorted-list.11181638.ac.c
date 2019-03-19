/*
 * @lc app=leetcode.cn id=83 lang=c
 *
 * [83] 删除排序链表中的重复元素
 *
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (43.84%)
 * Total Accepted:    16.9K
 * Total Submissions: 38.5K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
 * 
 * 示例 1:
 * 
 * 输入: 1->1->2
 * 输出: 1->2
 * 
 * 
 * 示例 2:
 * 
 * 输入: 1->1->2->3->3
 * 输出: 1->2->3
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (NULL == head) return NULL;
    if (NULL == head->next) return head;
    
    struct ListNode* cur = head->next;
    struct ListNode* pre = head;

    while(cur)
    {
        struct ListNode* next = cur->next;
        if (cur->val == pre->val)
        {
            pre->next = next;
            free(cur);
        }
        else
        {
            pre = cur;
        }
        
        cur = next;
    }
    
    return head;
}
