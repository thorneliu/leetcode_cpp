/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
 *
 * https://leetcode-cn.com/problems/add-two-numbers-ii/description/
 *
 * algorithms
 * Medium (46.11%)
 * Total Accepted:    2.6K
 * Total Submissions: 5.6K
 * Testcase Example:  '[7,2,4,3]\n[5,6,4]'
 *
 * 给定两个非空链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储单个数字。将这两数相加会返回一个新的链表。
 * 
 * 
 * 
 * 你可以假设除了数字 0 之外，这两个数字都不会以零开头。
 * 
 * 进阶:
 * 
 * 如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。
 * 
 * 示例:
 * 
 * 
 * 输入: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出: 7 -> 8 -> 0 -> 7
 * 
 * 
 */
/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
 *
 * https://leetcode-cn.com/problems/add-two-numbers-ii/description/
 *
 * algorithms
 * Medium (46.34%)
 * Total Accepted:    2.8K
 * Total Submissions: 6K
 * Testcase Example:  '[7,2,4,3]\n[5,6,4]'
 *
 * 给定两个非空链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储单个数字。将这两数相加会返回一个新的链表。
 * 
 * 
 * 
 * 你可以假设除了数字 0 之外，这两个数字都不会以零开头。
 * 
 * 进阶:
 * 
 * 如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。
 * 
 * 示例:
 * 
 * 
 * 输入: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出: 7 -> 8 -> 0 -> 7
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;

        while(l1)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }

        while(l2)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }

        bool carryon = false;
        ListNode dummy(0);
        ListNode* p = &dummy;
        while(!s1.empty() || !s2.empty())
        {
            auto op1 = s1.empty()? 0 : s1.top();
            auto op2 = s2.empty()? 0 : s2.top();

            auto digit = op1 + op2 + (carryon ? 1 : 0);
            carryon = (digit >= 10);
            ListNode* newNode = new ListNode(digit % 10);
            newNode->next = p->next;
            p->next = newNode;

            if (!s1.empty()) s1.pop();
            if (!s2.empty()) s2.pop();
        }

        if (carryon)
        {
            ListNode* newNode = new ListNode(1);
            newNode->next = p->next;
            p->next = newNode;
        }

        return p->next;
    }
};


