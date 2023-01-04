class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>mp;
        for(auto itr:tasks)
        {
            mp[itr]++;
        }
        int output=0;
        for(auto task:mp)
        {
            if(task.second==1)
                return -1;
            if(task.second%3==0)
              output+=task.second/3;
            else
                output+=task.second/3+1;
        }
        return output;
    }
};