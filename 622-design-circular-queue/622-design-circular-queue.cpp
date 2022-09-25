class MyCircularQueue {
public:
    vector<int>arr;
    int len;
    int size;
    MyCircularQueue(int k) {
        size=k;
        len=0;
    }
    
    bool enQueue(int value) {
        if(len==size)
            return false;
        else
        {
            arr.push_back(value);
            len++;
            return true;
        }
    }
    
    bool deQueue() {
        if(len==0)
            return false;
        else
        {
            arr.erase(arr.begin());
            len--;
            return true;
        }
    }
    
    int Front() {
        if(len==0)
            return -1;
        return arr[0];
    }
    
    int Rear() {
        if(len==0)
            return -1;
        return arr[len-1];
        
    }
    
    bool isEmpty() {
        if(len==0)
            return true;
        return false;
    }
    
    bool isFull() {
        if(len==size)
            return true;
        return false;
    }
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