//Runtime: 12 ms
//Memory Usage: 14.1 MB
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int c=0;unordered_map<int, int> um;multimap<int, int> MM;vector<int>ans;
    for(int i=0;i<nums.size();i++){
         um[nums[i]]++;
    }
    for (auto& it : um) {
        MM.insert({ it.second, it.first });
    }
    for (auto it = MM.rbegin(); it != MM.rend(); it++){
        if(c == k) break;
        else{
            c++;  
            ans.push_back(it->second);
        }
    }       
        return ans;
  }
};
