class TimeMap {
public:
    TimeMap() {
        
    }
    map<string,vector<pair<int,string>>>mp;
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        int n=mp[key].size();
        int start=0;
        int end=n-1;
        string ans="";
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(mp[key][mid].first==timestamp)
                return mp[key][mid].second;
            if(timestamp>mp[key][mid].first)
            {
                ans=mp[key][mid].second;
                start=mid+1;
            }
            else
                end=mid-1;
        }
        return ans;
        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */