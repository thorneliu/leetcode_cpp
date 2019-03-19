/*
 * @lc app=leetcode.cn id=138 lang=c
 *
 * [138] 复制带随机指针的链表
 *
 * https://leetcode-cn.com/problems/copy-list-with-random-pointer/description/
 *
 * algorithms
 * Medium (24.30%)
 * Total Accepted:    3.8K
 * Total Submissions: 15.8K
 * Testcase Example:  '{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}'
 *
 * 给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
 * 
 * 要求返回这个链表的深拷贝。 
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 
 * 输入：
 * 
 * {"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}
 * 
 * 解释：
 * 节点 1 的值是 1，它的下一个指针和随机指针都指向节点 2 。
 * 节点 2 的值是 2，它的下一个指针指向 null，随机指针指向它自己。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 你必须返回给定头的拷贝作为对克隆列表的引用。
 * 
 * 
 */
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     struct RandomListNode *next;
 *     struct RandomListNode *random;
 * };
 */
struct RandomListNode* newNode(int label)
{
    struct RandomListNode* p = (struct RandomListNode*)malloc(sizeof(struct RandomListNode));
    p->next = p->random = NULL;
    p->label = label;
    return p;
}

struct RandomListNode *copyRandomList(struct RandomListNode *head) {
    struct RandomListNode *p = head;
    while(p)
    {
        struct RandomListNode* pNext = p->next;
        struct RandomListNode* pCopy = newNode(p->label);
        pCopy->next = p->next;
        p->next = pCopy;

        p = pNext;
    }

    p = head;
    while(p && p->next)
    {
        struct RandomListNode* pCopy = p->next;
        if (p->random) pCopy->random = p->random->next;
        p = p->next->next;
    }

    struct RandomListNode* newHead = (head == NULL ? NULL : head->next);
    p = head;
    while(p && p->next)
    {
        struct RandomListNode* pCopy = p->next;
        struct RandomListNode* pNext = p->next->next;
        if (pCopy->next)   pCopy->next = pCopy->next->next;
        p->next = pNext;
        p = pNext;
    }

    return newHead;
}
