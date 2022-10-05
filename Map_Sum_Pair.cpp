class MapSum {
public:
    unordered_map<string, int> mp;
    MapSum() {
        
    }
    
    void insert(string key, int val) 
    {
        mp[key]=val;
    }
    
    int sum(string prefix) 
    {
        int sum=0;
        int n=prefix.size();
        for(auto it: mp)
        {
            string word=it.first.substr(0,n);
            if(word==prefix)
            {
                sum+=it.second;
            }
        }
        return sum;
    }
};
