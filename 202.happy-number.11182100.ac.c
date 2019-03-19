/*
 * @lc app=leetcode.cn id=202 lang=c
 *
 * [202] 快乐数
 *
 * https://leetcode-cn.com/problems/happy-number/description/
 *
 * algorithms
 * Easy (52.05%)
 * Total Accepted:    11.6K
 * Total Submissions: 22.3K
 * Testcase Example:  '19'
 *
 * 编写一个算法来判断一个数是不是“快乐数”。
 * 
 * 一个“快乐数”定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是无限循环但始终变不到
 * 1。如果可以变为 1，那么这个数就是快乐数。
 * 
 * 示例: 
 * 
 * 输入: 19
 * 输出: true
 * 解释: 
 * 12 + 92 = 82
 * 82 + 22 = 68
 * 62 + 82 = 100
 * 12 + 02 + 02 = 1
 * 
 * 
 */
typedef struct ListNode_tag
{
    int val;
    struct ListNode_tag* next;
}ListNode;

int getSumBitSqured(int a)
{
    int sum = 0;
    int i;
    while(a)
    {
        i = a%10;
        sum = sum + i * i;
        a = a/10;
    }
    
    return sum;
}

bool addListNode(ListNode** head, int value)
{
    if(NULL == head) return false;
    
    ListNode* p = *head;
    while(p->next != NULL)
    {
        if(p->next->val == value) 
        {
            printf("node with same val found\n");
            return false;
        }
 
        p = p->next;
    }
    
    ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
    if(NULL == newNode) return false;
    newNode->val = value;
    newNode->next = NULL;
    
    p->next = newNode;
    
    return true;
}

void freeNodes(ListNode** head)
{
    if(head == NULL) return;
    
    ListNode* pdelete = NULL;
    ListNode* pCurHead = *head;
    
    while(pCurHead->next)
    {
        pdelete = pCurHead;
        pCurHead = pCurHead->next;
        free(pdelete);
    }
    
    return;
}

bool isHappy(int n) {
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    head->val = 0xFFFFFFFF;
    head->next = NULL;
    
    while(true)
    {
        n = getSumBitSqured(n);
        if(1 == n)
        {
            freeNodes(&head);
            return true;
        }

        if(false == addListNode(&head, n))
        {
            freeNodes(&head);
            return false;
        }
    }
}
