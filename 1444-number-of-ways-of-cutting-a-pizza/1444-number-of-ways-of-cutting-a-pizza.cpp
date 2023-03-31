class Solution {
public:
    long long MOD = 1000000007;
    bool isValid(vector<string>&pizza, int startRow, int endRow, int startCol, int endCol)
    {
        for (int i = startRow; i <= endRow; i++)
        {
            for (int j = startCol; j <= endCol; j++)
            {
                if (pizza[i][j] == 'A') return true;
            }
        }
        return false;
    }
    int solve(vector<string>&pizza, vector<vector<vector<int>>>&dp, int startRow, int startCol, int cutsLeft)
    {
        int m = pizza.size(), n = pizza[0].size();
        if (cutsLeft == 0) return 1;
        
        if (dp[startRow][startCol][cutsLeft] != -1) return dp[startRow][startCol][cutsLeft];
        //============================================================================================
        long long ans = 0;
        //we are making a cut below the rowIndex = 'row'
        for (int row = startRow; row < m - 1; row++) 
        {
            bool upperHalfValid = isValid(pizza, startRow, row, startCol, n - 1);
            bool lowerHalfValid = isValid(pizza, row + 1, m - 1, startCol, n - 1);
            if (upperHalfValid && lowerHalfValid)  //upperHalf will be given away
            {
                int nextWays =  (solve(pizza, dp, row + 1, startCol, cutsLeft - 1)); //lowerHalf
                ans = (ans + nextWays) % MOD;
            }
        }
        //======================================================================================
         //we are making a cut towards the right of colIndex = 'col'
        for (int col = startCol; col < n - 1; col++)
        {
            bool leftHalfValid = isValid(pizza, startRow, m - 1, startCol, col); 
            bool rightHalfValid = isValid(pizza, startRow, m - 1, col + 1, n - 1);
            if (leftHalfValid && rightHalfValid) //leftHalf will be given away
            {
                int nextWays = solve(pizza, dp, startRow, col + 1, cutsLeft - 1); //rightHalf
                ans = (ans + nextWays) % MOD;
            }
        }
        //===============================================================================================
        return dp[startRow][startCol][cutsLeft] = (int)ans;
    }
    int ways(vector<string>& pizza, int k)
    {
        int m = pizza.size(), n = pizza[0].size();
        vector dp(m, vector(n, vector<int>(k, -1)));
        int ans = solve(pizza, dp, 0, 0, k - 1);
        return ans;
        
    }
};