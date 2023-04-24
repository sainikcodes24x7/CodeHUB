class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(),stones.end());
        int sz=stones.size();
        if(sz==1)
            return stones[0];
        int i=sz-1;
        int j=sz-2;
        
        while(j>=0)
        {
            if(stones[i]==stones[j])
            {
                i-=2;
                j-=2;
                stones.pop_back();
                stones.pop_back();
                if(stones.size()==0)
                    return 0;
            }
            else
            {
                stones[j]=abs(stones[i]-stones[j]);
                i--;
                j--;
                stones.pop_back();
                sort(stones.begin(),stones.end());
            }
        }
        return stones[0];
    }
};