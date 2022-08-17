class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string>charac={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string>u;
        
        for(auto word:words)
        {
            string s;
            for(auto c:word)
                s+=charac[c-'a'];
            u.insert(s);
        }
        return u.size();
    }
};