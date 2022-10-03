class Solution {
public:
    int memorizedWay(string s, int i, vector<int>& dp){
        if(i == s.size())   return 1;
        if(dp[i] != -1) return dp[i];
        int ans = 0;
        
        for(int k = i; k<s.size() && k<i+2; k++){
            string num = s.substr(i, k-i+1);
            int numb = stoi(num);
            if(num[0] != '0' && numb > 0 && numb <=26)
                ans += memorizedWay(s, k+1, dp);
        }
        return dp[i] = ans;
    }
    
    int numDecodings(string s){
        int n = s.size();
        vector<int>dp (n+1, -1);
        return memorizedWay(s, 0, dp);
    }
};
