class Solution:
    def numDistinct(self, s, t):
        dp = [[0] * (len(s) + 1) for _ in range(len(t) + 1)]
        for col in range(len(dp[0])):
            dp[0][col] = 1
        for x in range(1, len(s) + 1):
            for y in range(1, len(t) + 1):
                if s[x - 1] == t[y - 1]:
                    dp[y][x] = dp[y - 1][x - 1] + dp[y][x - 1]
                else:
                    dp[y][x] = dp[y][x - 1]
        return dp[-1][-1]
