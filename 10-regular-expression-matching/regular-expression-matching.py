class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        
        dp = {}
        
        def recur(i, j):
                
            if (i, j) not in dp:
                if i == len(s) and j == len(p):
                    dp[(i, j)] = True
                    return True

                if j>=len(p):
                    dp[(i, j)] = False
                    return False

                if j == len(p)-1:
                    if i<len(s) and (p[j] == '.' or s[i] == p[j]):
                        dp[(i, j)] = recur(i+1, j+1)
                        return dp[(i, j)]
                    else:
                        dp[(i, j)] = False
                        return dp[(i, j)]

                if p[j+1]!='*':
                    if i<len(s) and (p[j] == s[i] or p[j] == '.'):
                        dp[(i, j)] = recur (i+1, j+1)
                    else:
                        dp[(i, j)] = False
                        
                    return dp[(i, j)]
                else:
                    if i<len(s) and (p[j] == s[i] or p[j] == '.'):
                        dp[(i, j)] = recur(i+1, j) or recur(i, j+2)
                    else:
                        dp[(i, j)] = recur(i, j+2)
                        
                    return dp[(i, j)]

            return dp[(i, j)]
        
        return recur(0, 0)