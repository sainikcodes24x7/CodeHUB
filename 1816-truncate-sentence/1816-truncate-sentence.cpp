class Solution {
public:
    string truncateSentence(string s, int k) {
        string ans;
        for(auto word:s)
        {
            if(word==' ')
            k--;
            if(k==0)
                break;
            ans+=word;
            
            
        }
        return ans;
    }
};