class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        
        int n=heights.size();
        
     
        if(n==1) return 0;
        
        
        int b=bricks,l=ladders;
        
        for(int i=1;i<n;i++)
        {
           
            int diff=heights[i]-heights[i-1];
            
            
            if(diff>0)
            {
                pq.push(diff);
                b-=diff;
                
                if(b<0)
                {
                    
                    if(l<=0) return i-1;
                    else{
                        
                        int temp=pq.top();
                        pq.pop();
                        b+=temp;
                        l--;
                    }
                }
            }
        }
      
        return n-1;
    }
};
