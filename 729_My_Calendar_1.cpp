class MyCalendar {
public:
    map< int,int > m;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        m[start]++;
        m[end]--;
        
            int sum=0;
        for(auto it: m){
               
                sum+=it.second;
                if(sum>1){
                        m[start]--;
                        m[end]++;
                        return false;
                }
        }
            return true;
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
