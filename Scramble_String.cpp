class Solution {
public:
    bool isScramble(std::string s1, std::string s2) noexcept {
        const int n = std::size(s1);
        int8_t memo[31][31][31]{};        
        std::function<bool (int, int, int)> dfs = [&] (int i, int j, int k) noexcept {
            if (i == j)
                return s1[i] == s2[k];            
            if (memo[i][j][k])
                return memo[i][j][k] > 0;            
            for (int m = 0; m < j - i; ++m)
                if (dfs(i, i + m, k) && dfs(i + m + 1, j, k + m + 1) || dfs(i, i + m, k + (j - i) - m) && dfs(i + m + 1, j, k)) {
                    memo[i][j][k] = 1;
                    return true;
                }            
            memo[i][j][k] = -1;
            return false;
        };        
        return dfs(0, n - 1, 0);
   } 
};
