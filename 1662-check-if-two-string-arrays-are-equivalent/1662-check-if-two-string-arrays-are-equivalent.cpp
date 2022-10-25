class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1="";
        string s2="";
        for(auto itr:word1)
        {
            s1+=itr;
        }
         for(auto itr:word2)
        {
            s2+=itr;
        }
        return s1==s2;
    }
};