class Solution {
public:
    vector<int> findOriginalArray(vector<int>& arr) {
        if(arr.size()%2)
            return {};
        multiset<int> s(begin(arr), end(arr));
        
        vector<int>ans;
        for(int i=0;i<arr.size();i+=2)
        {
            int ele=*s.begin();
            //cout<<ele<<" ";
            s.erase(s.begin());
            ans.push_back(ele);
            if(s.find(2*ele)==s.end())
                return {};
            
                s.erase(s.find(2*ele));
                
            
        }
        return ans;
    }
};