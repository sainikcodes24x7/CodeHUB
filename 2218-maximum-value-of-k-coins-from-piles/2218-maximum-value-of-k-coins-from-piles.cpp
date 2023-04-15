class Solution {
public:
    const int inf = 1e9;
    int dp[1001][2001];
    int help(int idx, int k, vector<vector<int>> &piles)
    {
        // if no coins left then return 0
        if (k == 0)
            return 0;

        // if we have processed all the piles
        if (idx == piles.size())
        {
            // if k is 0 then we have chosen all the coins so return 0
            if (k == 0)
                return 0;   
            // if k is not 0, then this is not valid so return -infinity
            return -inf;
        }

        // if we have calculated the state before then return it
        if (dp[idx][k] != -1)
            return dp[idx][k];
            
        // for the current state initialize answer as 0
        int ans = -inf;

        // case1: take coins from the current prices {we can choose maximum 'min(k, current pile size)' coins from the current pile}
        for (int i = 0; i < min(k, (int)piles[idx].size()); i++)
            ans = max(ans, piles[idx][i] + help(idx + 1, k - (i + 1), piles));

        // -----------------max(take,nottake)----------------
        return dp[idx][k] = max(ans, help(idx + 1, k, piles));
    }
    int maxValueOfCoins(vector<vector<int>> &piles, int k)
    {
        memset(dp, -1, sizeof(dp));
        int n = piles.size();

        // storing pref in the piles itself
        for (int i = 0; i < n; i++)
            for (int j = 1; j < piles[i].size(); j++)
                piles[i][j] += piles[i][j - 1];

        // answer
        return help(0, k, piles);
    }
};