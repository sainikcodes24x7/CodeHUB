class Encrypter {
    unordered_map<char,string> kmap;
    unordered_map<string,int> rmap;
public:
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dic) {
        int n = keys.size();
        for(int i  = 0 ; i < n ; ++i){
            kmap[keys[i]] = values[i];
        }
        for(auto &x : dic){
            //rmap[encrypt(x)]++;
            auto p=encrypt(x);
            if(p.size())
                rmap[p]++;
        }
    }
    
    string encrypt(string word1) {
        string ans;
        for(char x : word1){
            if(kmap.count(x)==0)
                return "";
            ans += kmap[x];
        }
        return ans;
    }
    int decrypt(string word2) {
        return rmap.count(word2)?rmap[word2]:0;
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */