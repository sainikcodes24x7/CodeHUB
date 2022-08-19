class Solution {
public:
    bool isPossible(vector<int>& nums) {
        // dec a hashmap to store freq of each elem
        unordered_map<int,int>freq;
        for(auto itr:nums)
        {
            freq[itr]++;
        }
        // another hashmap to check whether a subsequence can be formed or not
        unordered_map<int,int>subs;
        for(auto i:nums)
        {
            if(freq[i]==0)
                continue;
            freq[i]--;
            
            //this is for including a num in the existing subsequence
            if(subs[i-1]>0)
            {
                subs[i-1]--;
                subs[i]++;
            }
            
            //this is for forming a new subsequence with current num
            else if(freq[i+1] and freq[i+2])
            {
                freq[i+1]--;
                freq[i+2]--;
                subs[i+2]++;
            }
            else
                return false;
        }
        return true;
    }
};