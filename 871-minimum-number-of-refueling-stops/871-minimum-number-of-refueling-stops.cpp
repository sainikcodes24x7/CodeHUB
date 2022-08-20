class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
     /*   if(startFuel>=target)
            return 0;
        int s=0,c=0;
        for(int i=0;i<stations.size();i++)
        {
            //int k=startFuel;
            startFuel-=stations[i][0];
            if(startFuel-=stations[i][0] <=0)
            {
                startFuel+=stations[i][1]+stations[i][0];
                c++;
            }
            
           /*  if(startFuel<=0)
            {
                c++;
                startFuel+=stations[i][1];
            }
            */
        /*    s+=stations[i][0];
            
           
        }
        if(s>=target)
        return c;
        return -1;
        */
     /*   ** CORNER CASES:**

if the start fuel is less than then position of the first fuel station than return -1 as its will not be possible to reach the first fuel station

if target distance is smaller than the startfuel return 0 as there will be no need to refill**

so first we will check if the first fuel station is at distance <= startfuel if yes then we will push its fuel to max heap
and after pushing we will add elements of heap into startfuel until it is equal to target
*/
        int i=0,ans;
        priority_queue<int,vector<int>>pq;
        for(ans=0;startFuel<target;ans++){
        while(i<stations.size() and stations[i][0]<=startFuel)
        {
            pq.push(stations[i++][1]);
            
        }
            if(pq.empty())
                return -1;
            startFuel+=pq.top();
            pq.pop();
        }
        return ans;
    }
};