class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_set<int>vis(stones.begin(),stones.end());
        unordered_map<int,unordered_set<int>>jumps;
        jumps[0]={1};
        int maxreached=1;
        for(auto itr:stones)
        {
            if(itr>maxreached)
                return false;
        
        for(int j:jumps[itr])
        {
            if(vis.find(j+itr)!=vis.end())
            {
                jumps[itr+j].insert(j-1);
                jumps[itr+j].insert(j);
                jumps[itr+j].insert(j+1);
                maxreached=max(maxreached,itr+j+1);
            }
        }
            
    }
        return !jumps[stones.back()].empty();
    }
};