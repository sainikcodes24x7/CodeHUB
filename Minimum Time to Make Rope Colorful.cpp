class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
      int ans = 0;

    stack<int>s;
    for(int i=0; i<colors.size(); i++)
    {
        if(s.empty()||(colors[s.top()]!=colors[i]))
        {
            s.push(i);
        }
        else if(colors[s.top()]==colors[i])
        {
            if(neededTime[s.top()]<neededTime[i])
            {
                ans+=neededTime[s.top()];
                s.pop();
                s.push(i);
            }
            else
            {
                ans+=neededTime[i];
            }
        }
    }
    
    return ans;

    }
};
