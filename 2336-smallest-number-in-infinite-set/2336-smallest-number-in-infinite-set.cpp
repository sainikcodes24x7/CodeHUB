class SmallestInfiniteSet {
public:
    set<int>ans;
    int x=1;
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        ans.insert(x);
        int ret = x;
        auto it = ans.find(x);
        while(it!=ans.end() && *it==x){
            x++;
            it++;
        }
        return ret;
    }
    
    void addBack(int num) {
       if(ans.find(num)!=ans.end()){
            ans.erase(num);
           x = (x>num) ? num:x;
    }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */