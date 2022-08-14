class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        stack<int>st;
        for(auto i:asteroids)
        {
            if(i>0)
                st.push(i);
            else
            {
                while(!st.empty() and st.top()>0 and st.top()<abs(i))
                    st.pop();
                    
                if(!st.empty() and st.top()==abs(i))
                    st.pop();
                else if(st.empty() || st.top()<0)
                    st.push(i);
            }
        }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};