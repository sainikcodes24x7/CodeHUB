class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        for(auto itr:words)
        {
            bool flag=true;
            for(int i=0;i<itr.size();++i)
            {
                for(int j=0;j<itr.size();++j)
                {
                    if((pattern[i]==pattern[j]) != (itr[i]==itr[j]))
                        flag=false;
                }
            }
            if(flag==true)
            {
                ans.push_back(itr);
            }
        }
        return ans;
    }
};