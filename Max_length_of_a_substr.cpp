class Solution {
public:
    int ans=0;
    
    bool isUnique(string s){
        unordered_map<char, int> mp;
        
        for(auto a:s){
            mp[a]++;
            if(mp[a]>1)
                return false;
        }
        return true;
    }
    
    void helper(vector<string>& arr, int ind, string subseq) {
        
        if(ind>=arr.size()) {
            int len=subseq.length();
            ans = max(ans, len);
            return;
        }
        
        helper(arr, ind+1, subseq); 
        
        if(isUnique(subseq+arr[ind])) {
            helper(arr, ind+1, subseq+arr[ind]);
        }
    }
    
    int maxLength(vector<string>& arr) {
        string temp="";
        helper(arr, 0, temp);
        return ans;
    }
};
