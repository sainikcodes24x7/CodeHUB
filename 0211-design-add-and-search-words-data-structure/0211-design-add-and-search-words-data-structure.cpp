class WordDictionary {
public:
    vector<string>v;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        v.push_back(word);
    }
    
    bool search(string word) {
        int n=word.size();
        int c=0;
        for(int j=0;j<v.size();j++)
        {
            if(v[j].size()==n)
            {
                for(int i=0;i<n;i++)
                {
                    if(v[j][i]==word[i]|| word[i]=='.')
                    {
                        c++;
                    }
                    else
                    {
                        c=0;
                        break;
                    }
                }
            }
            if(c==n)
                return true;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */