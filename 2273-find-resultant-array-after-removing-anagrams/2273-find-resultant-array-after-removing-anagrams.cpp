class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        //int n=;
        for(int i=1;i<words.size();i++)
        {
            string word1=words[i];
            sort(word1.begin(),word1.end());
            
            string word2=words[i-1];
            sort(word2.begin(),word2.end());
            
            if(word1==word2)
            {
                words.erase(words.begin()+i);
                i--;
            }
        }
        return words;
    }
};