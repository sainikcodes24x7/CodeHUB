class StockSpanner {
public:
    stack<pair<int,int>>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int c=0;
        while(!st.empty() and st.top().first<=price)
        {
            c+=st.top().second;
            st.pop();
        }
        c++;
        st.push({price,c});
        return c;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */