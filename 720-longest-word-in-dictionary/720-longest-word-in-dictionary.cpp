class Solution {
public:
    bool isvalid(string word, unordered_set<string>&st, int &cnt)
    {
        if(word.size()==1 and st.find(word)!=st.end())
            return true;
        word.pop_back();
        if(st.find(word)!=st.end())
        {
            cnt++;
            return isvalid(word,st,cnt);
        }
        return false;
    }
    string longestWord(vector<string>& words) {
        int n=words.size();
        unordered_set<string>st(words.begin(),words.end());
        int maxcnt=INT_MIN;
        string str="";
        sort(words.begin(),words.end());
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            if(isvalid(words[i],st,cnt) and cnt>maxcnt)
            {
                maxcnt=cnt;
                str=words[i];
            }
        }
        return str;
    }
};