class MedianFinder {
public:
    priority_queue<int>MaxH;
    priority_queue<int,vector<int>,greater<int>>MinH;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(MaxH.empty() || MaxH.top()>=num){
            MaxH.push(num);
        }else{
            MinH.push(num);
        }        
        if(abs((int)MaxH.size()-(int)MinH.size())>1){
            if(MaxH.size()>MinH.size()){
                MinH.push(MaxH.top());
                MaxH.pop();
            }else{
                MaxH.push(MinH.top());
                MinH.pop();
            }
        }
    }
    
    double findMedian() {
        if(MaxH.size()==MinH.size()){
            double ans=(MaxH.top()+MinH.top())*1.0/2;
            return ans;
        }else{
            if(MaxH.size()>MinH.size()){
                return MaxH.top();
            }else{
                return MinH.top();
            }
        }
    }
};