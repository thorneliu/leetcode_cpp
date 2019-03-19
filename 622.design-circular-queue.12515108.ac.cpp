/*
 * @lc app=leetcode.cn id=622 lang=cpp
 *
 * [622] Design Circular Queue
 *
 * https://leetcode-cn.com/problems/design-circular-queue/description/
 *
 * algorithms
 * Medium (37.54%)
 * Total Accepted:    4.4K
 * Total Submissions: 11.8K
 * Testcase Example:  '["MyCircularQueue","enQueue","enQueue","enQueue","enQueue","Rear","isFull","deQueue","enQueue","Rear"]\n[[3],[1],[2],[3],[4],[],[],[],[4],[]]'
 *
 * 设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于
 * FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。
 * 
 * 
 * 循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。
 * 
 * 你的实现应该支持如下操作：
 * 
 * 
 * MyCircularQueue(k): 构造器，设置队列长度为 k 。
 * Front: 从队首获取元素。如果队列为空，返回 -1 。
 * Rear: 获取队尾元素。如果队列为空，返回 -1 。
 * enQueue(value): 向循环队列插入一个元素。如果成功插入则返回真。
 * deQueue(): 从循环队列中删除一个元素。如果成功删除则返回真。
 * isEmpty(): 检查循环队列是否为空。
 * isFull(): 检查循环队列是否已满。
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * MyCircularQueue circularQueue = new MycircularQueue(3); // 设置长度为 3
 * 
 * circularQueue.enQueue(1);  // 返回 true
 * 
 * circularQueue.enQueue(2);  // 返回 true
 * 
 * circularQueue.enQueue(3);  // 返回 true
 * 
 * circularQueue.enQueue(4);  // 返回 false，队列已满
 * 
 * circularQueue.Rear();  // 返回 3
 * 
 * circularQueue.isFull();  // 返回 true
 * 
 * circularQueue.deQueue();  // 返回 true
 * 
 * circularQueue.enQueue(4);  // 返回 true
 * 
 * circularQueue.Rear();  // 返回 4
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 所有的值都在 0 至 1000 的范围内；
 * 操作数将在 1 至 1000 的范围内；
 * 请不要使用内置的队列库。
 * 
 * 
 */
class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        dataList_ = vector<int>(k, 0);
        capacity_ = k;
        head_ = -1;
        tail_ = -1;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) return false;
        if (head_ == -1 && tail_ == -1)
        {
            head_ = tail_ = 0;
        }
        else
        {
            tail_ = (tail_ + 1) % capacity_;
        }
        
        dataList_[tail_] = value;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) return false;
        if (head_ == tail_)
        {
            head_ = tail_ = -1;
        }
        else
        {
            head_ = (head_ + 1) % capacity_;
        }
        
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        return isEmpty()? -1 : dataList_[head_];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        return isEmpty()? -1 : dataList_[tail_];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return (tail_ == -1 && head_ == -1);
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return tail_ == (head_ - 1) 
            || (tail_ == head_ + capacity_ - 1);        
    }
    
    private:
        vector<int> dataList_;
        int head_;
        int tail_;
        int capacity_;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
