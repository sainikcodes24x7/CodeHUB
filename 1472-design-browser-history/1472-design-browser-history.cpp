class BrowserHistory {
public:
    int ele;
    vector<string>arr;
    BrowserHistory(string homepage) {
        arr.push_back(homepage);
        ele=0;
    }
    
    void visit(string url) {
        int l=arr.size()-1;
        while(l>ele)
        {
            arr.pop_back();
            l--;
        }
        ele++;
        arr.push_back(url);
    }
    
    string back(int steps) {
        ele-=steps;
        if(ele<0)
            ele=0;
        return arr[ele];
    }
    
    string forward(int steps) {
        ele+=steps;
        if(ele>=arr.size())
            ele=arr.size()-1;
        return arr[ele];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */