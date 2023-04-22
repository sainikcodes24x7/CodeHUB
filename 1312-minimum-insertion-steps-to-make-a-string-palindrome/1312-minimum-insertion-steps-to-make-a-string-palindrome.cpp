class Solution {
public:
    int minInsertions(string s) 
    {
        vector<int> memo(s.length(),0);
        int prev,temp;
        for(int i=s.length()-2;i>=0;i--)
        {
            prev=0;                                          //This stores the value at memo[i+1][j-1];
            for(int j=i;j<s.length();j++)
            {
                temp=memo[j];                               //Get the value of memo[i+1][j].
                memo[j]=s[i]==s[j]?prev:1+min(memo[j],memo[j-1]);     //memo[j]=memo[i+1][j], memo[j-1]=memo[i][j-1], prev=memo[i+1][j-1].
                prev=temp;                        //Store the value of memo[i+1][j] to use it as memo[i+1][j-1] in the next iteration.
            }
        }
        return memo[s.length()-1];
    }
};