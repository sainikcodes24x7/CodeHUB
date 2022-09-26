class Solution:
	def equationsPossible(self, equations: List[str]) -> bool:
		graph = defaultdict(set)
		not_equal = []
		
		for i in equations:
			if i[1:3] == "==":
				graph[i[0]].add(i[-1])
				graph[i[-1]].add(i[0])
			else:
				not_equal.append((i[0], i[-1]))
				
		for i in not_equal:
			if self.dfs(i[0], i[-1], graph, set()):
				return False
		return True
	
	def dfs(self, beg, target, graph, visited):
		if beg == target:
			return True
		
		visited.add(beg)
		for i in graph[beg]:
			if i not in visited and self.dfs(i, target, graph, visited):
				return True
			
		return False