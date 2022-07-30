class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>ans;
        int n1=words1.size();
        int n2=words2.size();
        
        int max_cnt[26]={0};
        for(auto wrd:words2)
        {
            int max2[26]={0};
            for(auto c:wrd){
            int x=c-'a';
            max2[x]++;
            max_cnt[x]=max(max_cnt[x],max2[x]);
            }
        }
        for(auto w1:words1)
        {
            int max1[26]={0};
            for(auto c:w1){
            int x=c-'a';
            max1[x]++;
            }
            int i;
            for(i=0;i<26;i++)
            {
                if(max1[i]<max_cnt[i])
                    break;
            }
            if(i==26)
                ans.push_back(w1);
            
        }
        return ans;
    }
};