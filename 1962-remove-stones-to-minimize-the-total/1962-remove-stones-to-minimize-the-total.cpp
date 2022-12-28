class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n=piles.size();
        priority_queue<int>pq;
        for(auto &itr:piles)
        {
            pq.push(itr);
        }
        int high;
        while(k>0 and !pq.empty())
        {
            high=pq.top();
            pq.pop();
            high-=high/2;
            pq.push(high);
            k--;
        }
        int sum=0;
        while(!pq.empty())
        {
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};