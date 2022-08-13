class Solution {
public:
    bool isPossible(string s, int i, int j, unordered_map<string,int>mp, int len)
    {
        unordered_map<string,int>freq;
        int k=i;
        while(k<=j-len+1)
        {
            string str=s.substr(k,len);
            freq[str]++;
            k+=len;
        }
        for(auto i:freq)
        {
            if(i.second!=mp[i.first])
                return false;
        }
        return true;
        
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int>mp;
        
        // storing the frequency of characters
        for(int k=0;k<words.size();k++)
        {
            mp[words[k]]++;
        }
        int n=words.size();
        int m=words[0].size();
        int windsize=n*m;
        int i=0;
        int j=windsize-1;
        vector<int>ans;
        
        // apply sliding window 
        while(j<s.size())
        {
            if(isPossible(s,i,j,mp,m))
                ans.push_back(i);
            i++;
            j++;
        }
        return ans;
    }
};