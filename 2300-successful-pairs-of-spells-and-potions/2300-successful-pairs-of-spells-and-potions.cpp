class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
         int postfix[100001] = {0};
        for(auto potion: potions) postfix[potion]++;
        for(int i=99999; i>=0; --i) postfix[i] += postfix[i+1];

        //No need extra space at all for storing final result
        for(int i=0; i<spells.size(); ++i){
            long long val = success / (long long) spells[i];
            if(success % (long long) spells[i] != 0) val++;

            spells[i] = val <= 1e5 ? postfix[val] : 0;
        }
        return spells;
    }
};