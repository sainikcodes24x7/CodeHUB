class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        {
        int count = 0;
        
        unordered_map<string, int> mp;
        for(int i = 0 ; i < words.size(); i++)
        {
            string s = words[i];
            reverse(s.begin(), s.end());
            
            if(mp[s] > 0)
            {
                count += 4;
                mp[s]--;
            }
            else
                mp[words[i]]++;
        }
        
        for(auto i : mp)
        {
            if(i.first[0] == i.first[1] and i.second > 0)
            {
                return count + 2;
            }
        }
        return count;   
    }
    }
};