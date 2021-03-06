/*
 * @lc app=leetcode.cn id=328 lang=c
 *
 * [328] 奇偶链表
 *
 * https://leetcode-cn.com/problems/odd-even-linked-list/description/
 *
 * algorithms
 * Medium (53.89%)
 * Total Accepted:    6.6K
 * Total Submissions: 12.3K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。
 * 
 * 请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。
 * 
 * 示例 1:
 * 
 * 输入: 1->2->3->4->5->NULL
 * 输出: 1->3->5->2->4->NULL
 * 
 * 
 * 示例 2:
 * 
 * 输入: 2->1->3->5->6->4->7->NULL 
 * 输出: 2->3->6->7->1->5->4->NULL
 * 
 * 说明:
 * 
 * 
 * 应当保持奇数节点和偶数节点的相对顺序。
 * 链表的第一个节点视为奇数节点，第二个节点视为偶数节点，以此类推。
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
struct ListNode* oddEvenList(struct ListNode* head) {
    struct ListNode oddHead;
    struct ListNode eveHead;
    memset(&oddHead, 0, sizeof(struct ListNode));
    memset(&eveHead, 0, sizeof(struct ListNode));
    
    struct ListNode* podd = &oddHead;
    struct ListNode* peve = &eveHead;
    
    struct ListNode* p = head;
    int index = 1;
    
    while(p)
    {
        struct ListNode* pnext = p->next;
        if (index % 2 == 0)
        {
            peve->next = p;
            peve = p;
            peve->next = NULL;
        }
        else
        {
            podd->next = p;
            podd = p;
            podd->next = NULL;
        }
        
        index++;
        p = pnext;
    }
    
    podd->next = eveHead.next;
    //peve->next = NULL;
    return oddHead.next;
}
