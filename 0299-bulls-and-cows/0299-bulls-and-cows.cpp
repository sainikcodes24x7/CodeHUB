class Solution {
public:
    string getHint(string secret, string guess) {
        int n=secret.size();
        int bulls=0,cows=0;
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;
        
        for(int i=0;i<n;i++)
        {
            if(secret[i]==guess[i])
                bulls++;
            else
            {
                mp1[secret[i]-'0']++;
                mp2[guess[i]-'0']++;
            }
        }
        for(auto itr:mp1)
        {
            if(mp2.find(itr.first)!=mp2.end())
                cows+=min(mp2[itr.first],itr.second);
        }
        
        string s="";
        s+=to_string(bulls)+"A"+ to_string(cows)+"B";
        return s;
    }
};