/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
 struct ListNode* reverseList(struct ListNode* head) {
    if (NULL == head) return NULL;
    
    struct ListNode* pnewHead;
    struct ListNode* pfakeHead;
    
    pnewHead = head;
    pfakeHead = head;
    while(pfakeHead->next != NULL)
    {
        struct ListNode* reversedNode = pfakeHead->next;
        pfakeHead->next = reversedNode->next;
        
        reversedNode->next = pnewHead;
        pnewHead = reversedNode;
    }
    
    head->next = NULL;
    return pnewHead;
}

bool isPalindrome(struct ListNode* head) {
    //using the solved leetcode code to reverse the rest half of the linked list
    //however, the input list was changed after this func... too bad...
    
    if(head == NULL || head->next == NULL) return true;
    
    int len = 0;
    int i = 0;
    struct ListNode* p = head;
    while(p)
    {
        i++;
        p = p->next;
    }
    
    len = i;
    int lenOfRightHalf = len/2;
    
    i = 0;
    p = head;
    while(i < (len - lenOfRightHalf))
    {
        i++;
        p = p->next;
    }
    
    struct ListNode* s = reverseList(p);
    p = head;
    i = 0;
    while(i < lenOfRightHalf)
    {
        i++;
        if(s->val != p->val) return false;
        s = s->next;
        p = p->next;
    }
    
    return true;
}
