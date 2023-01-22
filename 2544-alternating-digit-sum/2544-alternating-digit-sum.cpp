class Solution {
public:
    int alternateDigitSum(int n) {
     stack<int>st;
        while(n!=0)
        {
            int p=n%10;
            st.push(p);
            n/=10;
        }
        int sum=0;
        int c=0;
        while(!st.empty())
        {
            if(c%2==0)
            {
                int k=st.top();
                sum+=k;
                st.pop();
            }    
            else
            {
                int k=-st.top();
                sum+=k;
                st.pop();
            }
            c++;
        }
        return sum;
    }
};