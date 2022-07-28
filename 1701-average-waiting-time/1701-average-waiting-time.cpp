class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double time=0;
        double waittime=0;
        
        for(auto &itr:customers)
        {
            //The first customer arrives at time 5
            /*time=max(itr[0],time);*/
            if(itr[0]>time)
                time=itr[0];
            
            //the chef takes his order and starts preparing it immediately at time 5
            int timestart=time+itr[1];
            
            //and finishes at time 7, so the waiting time of the first customer is 7 - 5 = 2.
            waittime=waittime+timestart-itr[0];
            
            //The second customer arrives at time 5 ie timestart
            time=timestart;
        }
        return waittime/customers.size();
    }
};