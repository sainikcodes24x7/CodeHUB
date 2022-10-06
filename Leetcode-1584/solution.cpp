struct cmp{
    constexpr bool operator()(vector<int>&a,vector<int>&b)const noexcept{
        return a[1]>b[1] ;
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
       priority_queue<vector<int>,vector<vector<int>>,cmp> pq ; 
       unordered_set<int> st ;
       int ans = 0 ;
       pq.push({0,0}) ;
       while(st.size()<points.size()){
           vector<int> top = pq.top() ;
           pq.pop() ;
           if(st.count(top[0])>0) continue ;
           st.insert(top[0]) ;
           ans += top[1] ;
           int src = top[0] ;
           for(int i=0;i<points.size();i++)
           {
                   int val = abs(points[src][0]-points[i][0])+abs(points[src][1]-points[i][1]) ;
                   if(st.count(i) == 0)
                   {
                       pq.push({i,val}) ;
                   }
           }
       }
     return ans ;
    }
};