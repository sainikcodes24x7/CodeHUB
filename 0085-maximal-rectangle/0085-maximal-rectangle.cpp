class Solution {
public:
    int solve(vector<int>&height)
    {
        int n=height.size();
        vector<int>leftsmaller(n);
        vector<int>rightsmaller(n);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(st.size()!=0 and height[i]<=height[st.top()])
            {
                st.pop();
            }
            if(st.size()==0)
            {
                leftsmaller[i]=-1;
            }
            else
            {
                leftsmaller[i]=st.top();
            }
            st.push(i);
        }
        while(st.size()!=0)
        {
            st.pop();
        }
        for(int i=n-1;i>=0;i--)
        {
            while(st.size()!=0 and height[i]<=height[st.top()])
            {
                st.pop();
            }
            if(st.size()==0)
            {
                rightsmaller[i]=n;
            }
            else
            {
                rightsmaller[i]=st.top();
            }
            st.push(i);
        }
        vector<int>width(n);
        for(int i=0;i<n;i++)
        {
            width[i]=rightsmaller[i]-leftsmaller[i]-1;
        }
        vector<int>area(n);
        for(int i=0;i<n;i++)
        {
            area[i]=width[i]*height[i];
        }
        int maxarea=INT_MIN;
        for(int i=0;i<n;i++)
        {
            maxarea=max(maxarea,area[i]);
        }
        return maxarea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix[0].size();
        int n=matrix.size();
        vector<int>arr(m,0);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='0')
                    arr[j]=0;
                else 
                    arr[j]++;
            }
            ans=max(ans,solve(arr));
        }
        return ans;
    }
};