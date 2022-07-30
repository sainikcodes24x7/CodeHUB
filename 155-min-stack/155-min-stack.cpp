class MinStack {
public:
    stack<int>st;
    stack<int>dummy;
   
    MinStack() {
        
    }
    
    void push(int val) {
        
        st.push(val);
        if(dummy.empty() || val<=getMin())
            dummy.push(val);
    }
    
    void pop() {
        if(st.top()==getMin())
            dummy.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return dummy.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */