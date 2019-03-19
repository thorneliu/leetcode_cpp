/*
 * @lc app=leetcode.cn id=61 lang=c
 *
 * [61] 旋转链表
 *
 * https://leetcode-cn.com/problems/rotate-list/description/
 *
 * algorithms
 * Medium (37.21%)
 * Total Accepted:    9.3K
 * Total Submissions: 24.9K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
 * 
 * 示例 1:
 * 
 * 输入: 1->2->3->4->5->NULL, k = 2
 * 输出: 4->5->1->2->3->NULL
 * 解释:
 * 向右旋转 1 步: 5->1->2->3->4->NULL
 * 向右旋转 2 步: 4->5->1->2->3->NULL
 * 
 * 
 * 示例 2:
 * 
 * 输入: 0->1->2->NULL, k = 4
 * 输出: 2->0->1->NULL
 * 解释:
 * 向右旋转 1 步: 2->0->1->NULL
 * 向右旋转 2 步: 1->2->0->NULL
 * 向右旋转 3 步: 0->1->2->NULL
 * 向右旋转 4 步: 2->0->1->NULL
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (!head) return NULL;
    
    struct ListNode* p = head;
    int len = 1;
    
    while(p->next != NULL)
    {
        p = p->next;
        len++;
    }
    
    k = k%len;
    printf("len = %d, k = %d.\n", len, k);
    
    struct ListNode *tail = p;
    printf("tail = %d.\n", tail->val);
    
    int i = 1;
    p = head;
    while(i < (len-k))
    {
        p = p->next;
        i++;
    }
    
    if (p->next == NULL) return head;
    
    //p->next is the new head and p is the tail now
    struct ListNode* newHead = p->next;
    p->next = NULL;
    
    //origional tail is next node is the original head
    tail->next = head;
    
    return newHead;
}
