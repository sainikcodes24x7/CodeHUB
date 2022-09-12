class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int n=tokens.size();
        if(n==0)
            return 0;
        if(power<tokens[0])
            return 0;
        int currsum=0;
        int maxsum=0;
        int last=n-1;
        for(int i=0;i<=last;i++)
        {
            maxsum=max(maxsum,currsum);
            if(power>=tokens[i])
            {
                currsum++;
                power-=tokens[i];
            }
            else
            {
                power+=tokens[last];
                currsum--;
                last--;
                
                if(power>=tokens[i])
                {
                    currsum++;
                    power-=tokens[i];
                }
                else
                {
                    break;
                }
            }
        }
        maxsum=max(maxsum,currsum);
        return maxsum;
    }
};