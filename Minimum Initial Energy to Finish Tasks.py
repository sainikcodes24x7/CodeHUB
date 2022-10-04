class Solution:
    def minimumEffort(self, tasks: List[List[int]]) -> int:
        tasks.sort(key=lambda x: x[1]-x[0])
        
        result=0
        
        for actual,minimum in tasks:
            result = max(result+actual,minimum)
            
        return result
      
s=Solution()
tasks = [[1,2],[2,4],[4,8]]
s.minimumEffort(tasks)
