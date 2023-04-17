class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& cd, int ex) {
        int mx =0;
        vector<bool> ans;
        for(int a : cd ) mx =max(mx,a);
        for(int a : cd){
            if(a+ex >= mx) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};