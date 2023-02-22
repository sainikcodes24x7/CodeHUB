class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int maxweight=-1,totalwt=0;
        for(int wt:weights)
        {
            maxweight=max(maxweight,wt);
            totalwt+=maxweight;
        }
        while(maxweight<totalwt)
        {
            int midwt=maxweight+(totalwt-maxweight)/2;
            int daysneed=1,currwt=0;
            for(int weight:weights)
            {
                if(weight+currwt>midwt)
                {
                    daysneed++;
                    currwt=0;
                }
                currwt+=weight;
            }
            if(daysneed>days)
                maxweight=midwt+1;
            else
                totalwt=midwt;
        }
        return maxweight;
    }
};