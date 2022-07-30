class Solution {
public:
   void maxFreq(string s, vector<int> &rep){
    
    vector<int> freq(26,0);
    
    for(int i=0; i<s.size(); i++){
        freq[s[i]-'a']++;
    }
    
    for(int i=0; i<26; i++){
        rep[i] = max(rep[i], freq[i]);
    }
    
}

bool check(string s, vector<int> rep){
    
    
    vector<int> freq(26,0);
    
    for(int i=0; i<s.size(); i++){
        freq[s[i]-'a']++;
    }
    
    
    for(int i=0; i<26; i++){
        
        if(rep[i] > freq[i]) return false;
        
    }
    
    
    return true;
    
}


vector<string> wordSubsets(vector<string>& word1, vector<string>& word2) {
    
    
    vector<int> rep(26,0);
    int n2 = word2.size();
    vector<string> res;
    int n1 = word1.size();
    
    for(int i=0; i<n2; i++){
        maxFreq(word2[i], rep);
    }
    
    
    for(int i=0; i<n1; i++){
        
        if(check(word1[i], rep)) res.push_back(word1[i]);
        
    }
    
    
    return res;
    
}
};