class Trie {
    private:
    Trie*children[26]={NULL};
        bool endofword= false;
public:
    Trie() {
        
    }
    
    void insert(string word) {
        Trie* cur=this;
        for(auto c:word)
        {
            if(cur->children[c-'a']==NULL)
                cur->children[c-'a']=new Trie();
            cur=cur->children[c-'a'];
        }
        cur->endofword=true;
    }
    
    bool search(string word) {
        Trie* cur=this;
        for(int i=0;i<word.length();++i)
        {
            if(cur->children[word[i]-'a']!=NULL)
                cur=cur->children[word[i]-'a'];
            else
                return false;
        }
        return cur->endofword;
    }
    
    bool startsWith(string prefix) {
        Trie* cur=this;
        for(int i=0;i<prefix.length();++i)
        {
            if(cur->children[prefix[i]-'a']!=NULL)
                cur=cur->children[prefix[i]-'a'];
            else
                return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */