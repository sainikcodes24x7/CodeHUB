class Solution:
    def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
        n = len(jobDifficulty)
        if n < d:
            return -1

        dp = [[-1] * (d + 1) for _ in range(n + 1)]
        
        def helper(index, dayleft):
            if dp[index][dayleft] != -1:
                return dp[index][dayleft]

            if dayleft == 1:
                return max(jobDifficulty[index :])

            else:
                best = float('inf')
                curr = 0
                for i in range(index, n - dayleft + 1):
                    curr = max(curr, jobDifficulty[i])
                    best = min(best, curr + helper(i + 1, dayleft - 1))
                    dp[index][dayleft] = best
            
                return best


        return helper(0, d)