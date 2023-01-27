class Solution {
public:
    bool word_join(string &word,unordered_map<string,int>&mp )
    {
        for(int i=1;i<word.size();i++)
        {
            //we split it letter wise from left and remaining word on right
            string leftpart=word.substr(0,i);
            string rightpart=word.substr(i);
            
            //we check if left part and right part both is present AND
            //for right part we call the function recurssively to check for the remaining word
            
            if(mp[leftpart] and (mp[rightpart] || word_join(rightpart,mp)))
                return true;
        }
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        // output array
        vector<string>output;
        
        //storing each word in unordered map
        unordered_map<string,int>mp;
        for(auto itr:words)
        {
            mp[itr]++;
        }
        
        //word-join srch
        for(auto itr:words)
        {
            // if the concatenated word exists we push in output array
            if(word_join(itr,mp))
                output.push_back(itr);
        }
        
        
        return output;
    }
};