class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //unordered_map<char,int>mp;
        int freq[26]={0};
        for(auto c:tasks)
        {
            freq[c-'A']++;
        }
        priority_queue<int>pendingtask;
        
        int time=0;
        
        for(auto f:freq)
        {
            if(f)
                pendingtask.push(f);
        }
        // task and time
        queue<pair<int,int>>upcomingtask;
        while(!upcomingtask.empty() || !pendingtask.empty())
        {
            if(!upcomingtask.empty() and upcomingtask.front().second<=time)
            {
                pendingtask.push(upcomingtask.front().first);
                upcomingtask.pop();
            }
            time++;
            if(!pendingtask.empty())
            {
                int task=pendingtask.top()-1;
                pendingtask.pop();
                if(task>0)
                    upcomingtask.push({task,time+n});
            }
        }
        return time;
    }
};