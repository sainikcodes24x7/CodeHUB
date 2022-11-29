class RandomizedSet 
 {
public:
    vector<int> nums; //for storing val
    unordered_map<int, int> mp; //for storing val and its index (nums)
    RandomizedSet() 
    {
        
    }
    
    bool insert(int val) 
    {
        if(mp.find(val) != mp.end()) return false; //when value exist
        nums.push_back(val); //storing val in nums
        mp[val] = nums.size()-1; //storing val and its index
        return true;
    }
    
    bool remove(int val) 
    {
        if(mp.find(val) == mp.end()) return false; //when value doesn't exist
        auto it = mp.find(val); //find val in mp;
        
        //put a last value of nums at the index of val and remove the last index value
        nums[it->second] = nums.back();
        nums.pop_back();
        
        //update last value index in map
        mp[nums[it->second]] = it->second; 
        mp.erase(val);
        return true;
    }
    
    int getRandom() 
    {
        //take any random number and do modules with size of nums 
        //to get number lies in nums index range and return it
        return nums[rand()%nums.size()];
    }
};