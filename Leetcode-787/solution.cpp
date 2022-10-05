class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
      k += 2 ;
      vector<vector<pair<int,int>>> graph(n) ;
      for(auto i:flights){
          graph[i[0]].push_back({i[1],i[2]}) ;
      }
      queue<pair<int,int>> bfs ;
      bfs.push({src,0}) ;
      int m = INT_MAX ;
      vector<int>costs (n,INT_MAX);
      while(!bfs.empty() && k>0){
          int temp = bfs.size() ;
          for(int i=0;i<temp;i++){
              pair<int,int> p = bfs.front() ;
              bfs.pop() ;
              int node = p.first ;
              int dist = p.second ;
              costs[node] = dist ;
              if(dist>=m) continue ;
              if(node==dst){
                  m = min(m,dist) ;
                  continue ;
              }
              for(auto j:graph[node]){
                  if(dist+j.second < costs[j.first])bfs.push({j.first,j.second+dist}) ;
              }
          }
          k-- ;
      }
     return m==INT_MAX?-1:m ;
    }
};