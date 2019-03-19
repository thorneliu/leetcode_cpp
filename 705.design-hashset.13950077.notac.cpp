/*
 * @lc app=leetcode.cn id=705 lang=cpp
 *
 * [705] Design HashSet
 *
 * https://leetcode-cn.com/problems/design-hashset/description/
 *
 * algorithms
 * Easy (52.87%)
 * Total Accepted:    2.8K
 * Total Submissions: 5.3K
 * Testcase Example:  '["MyHashSet","add","add","contains","contains","add","contains","remove","contains"]\n[[],[1],[2],[1],[3],[2],[2],[2],[2]]'
 *
 * 不使用任何内建的哈希表库设计一个哈希集合
 * 
 * 具体地说，你的设计应该包含以下的功能
 * 
 * 
 * add(value)：向哈希集合中插入一个值。
 * contains(value) ：返回哈希集合中是否存在这个值。
 * remove(value)：将给定值从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。
 * 
 * 
 * 
 * 示例:
 * 
 * MyHashSet hashSet = new MyHashSet();
 * hashSet.add(1);         
 * hashSet.add(2);         
 * hashSet.contains(1);    // 返回 true
 * hashSet.contains(3);    // 返回 false (未找到)
 * hashSet.add(2);          
 * hashSet.contains(2);    // 返回 true
 * hashSet.remove(2);          
 * hashSet.contains(2);    // 返回  false (已经被删除)
 * 
 * 
 * 
 * 注意：
 * 
 * 
 * 所有的值都在 [1, 1000000]的范围内。
 * 操作的总数目在[1, 10000]范围内。
 * 不要使用内建的哈希集合库。
 * 
 * 
 */
class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        basket_ = vector<Basket>(1000);
    }
    
    void add(int key) {
        auto hashval = key % 1000;
        basket_[hashval].add(key);
    }
    
    void remove(int key) {
        auto hashval = key % 1000;
        basket_[hashval].remove(key);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        auto hashval = key % 1000;
        return basket_[hashval].contains(key);
    }
private:
    struct ListNode{
        int val;
        ListNode* next;

        ListNode(int val_) : val(val_), next(nullptr){}
    };
    
    class Basket{
    public:
        Basket(){
            head_ = nullptr;
        }
        
        ~Basket(){
            ListNode* p = head_;
            while(p)
            {
                ListNode* pNext = p->next;
                delete p;
                p = pNext;
            }

            return;
        }

        void add(int key){
            if (contains(key)) return;
            
            ListNode* newNode = new ListNode(key);
            if (head_ == nullptr)
            {
                head_ = newNode;
            }
            else
            {
                newNode->next = head_;
                head_ =  newNode;
            }
            return;
        }

        void remove(int key)
        {
            ListNode dummy(0);
            dummy.next = head_;

            ListNode* p = &dummy;
            while(p->next)
            {
                if (p->next->val == key)
                {
                    ListNode* newNext = p->next->next;
                    ListNode* pDelete = p->next;
                    p->next = newNext;
                    if (pDelete == head_) head_ = nullptr;
                    delete pDelete;
                    return;
                }

                p = p->next;
            }

            return;
        }

        bool contains(int key)
        {
            ListNode* p = head_;
            while(p)
            {
                if (p->val == key) return true;
                p = p->next;
            }

            return false;
        }

    private:
        struct ListNode* head_;
};
    
vector<Basket> basket_;
    
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */
