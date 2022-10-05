class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int m=s1.size(),n=s2.size();
         vector<vector<int>>dp(m+1,vector<int>(n+1,0));
                
                for(int i=1;i<=m;i++){
                    for(int j=1;j<=n;j++){
                        if(s1[i-1]==s2[j-1]){
                            dp[i][j]=1+dp[i-1][j-1];
                        }else{
                            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                        }
                    }
                }
              
        int i=m,j=n;
        string ans="";
        while(j>=1 && i>=1){
            if(s1[i-1]==s2[j-1]){
                ans=s1[i-1]+ans;
                i--;j--;
            }else if(dp[i-1][j]>dp[i][j-1]){
                ans=s1[i-1]+ans;
                i--;
            }else{
                ans=s2[j-1]+ans;
                j--;
            }
        }
        
        while(i>=1){
            ans=s1[i-1]+ans;
            i--;
        }
        while(j>=1){
            ans=s2[j-1]+ans;
            j--;
        }
        
        return ans;
    }
};