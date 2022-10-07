class MyCalendarThree {
public:
    map<int,int>events;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        events[start]++;
        events[end]--;
        int cnt=0,ans=0;
        for(auto i:events)
        {
            cnt+=i.second;
            ans=max(ans,cnt);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */