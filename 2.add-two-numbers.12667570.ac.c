/*
 * @lc app=leetcode.cn id=2 lang=c
 *
 * [2] 两数相加
 *
 * https://leetcode-cn.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (32.64%)
 * Total Accepted:    86.4K
 * Total Submissions: 264.8K
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
 * 
 * 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 * 
 * 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * 
 * 示例：
 * 
 * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 0 -> 8
 * 原因：342 + 465 = 807
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
struct ListNode* newNode(int val)
{
    struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));
    p->val =val;
    p->next = NULL;
    return p;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    struct ListNode* pRes = &dummy;
    
    bool carry = false;
    while(l1 || l2)
    {
        int op1 = (l1 == NULL) ? 0 : l1->val;
        int op2 = (l2 == NULL) ? 0 : l2->val;
        int sum = op1 + op2 + (carry ? 1 : 0);
        carry = sum >= 10;
        
        pRes->next = newNode(sum % 10);
        pRes = pRes->next;
        
        if(l1) l1 = l1->next;
        if(l2) l2 = l2->next;
    }
    if (carry) pRes->next = newNode(1);
    
    return dummy.next;
}
