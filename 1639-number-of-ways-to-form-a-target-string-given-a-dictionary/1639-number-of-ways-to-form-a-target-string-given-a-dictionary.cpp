class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int mod = 1e9 + 7;
        int m = words.size(), n = words[0].size();
        
        // frequency array for each character in each column
        vector<vector<int>> freq(n, vector<int>(26, 0));
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                freq[j][words[i][j] - 'a']++;
            }
        }
        
        // dp array to store the number of ways to form the prefix of target
        vector<long long> dp(target.size() + 1, 0);
        dp[0] = 1;
        
        // fill dp array from left to right
        for (int j = 0; j < n; j++) {
            for (int i = target.size(); i > 0; i--) {
                dp[i] = (dp[i] + dp[i-1] * freq[j][target[i-1] - 'a']) % mod;
            }
        }
        
        return dp[target.size()];
    }
};