class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int tot_gas=0,tot_cost=0,cur_gas=0, start_idx=0;
        
        for(int i=0;i<n;i++)
        {
            tot_gas+=gas[i];
            tot_cost+=cost[i];
            
            cur_gas+=gas[i]-cost[i];
            if(cur_gas<0)
            {
                start_idx=i+1;
                cur_gas=0;
            }
        }
        if(tot_gas<tot_cost)
            return -1;
        return start_idx;
        
        
    }
};