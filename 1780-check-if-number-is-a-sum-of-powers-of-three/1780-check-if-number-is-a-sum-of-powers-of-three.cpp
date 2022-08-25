class Solution {
public:
    bool checkPowersOfThree(int n) {
     /*   int i=1,sum=0;
        while(i<sqrt(n))
        {
            sum+=pow(3,i);
            if(sum==n)
                return true;
            i++;
        }
        return false;
        */
    int num=1;
    int sum=0;
    stack<int>st;
    
    while(num<=n)
    {
        st.push(num);
        num*=3;
    }
    while(!st.empty())
    {
        if(sum+st.top()<=n)
            sum+=st.top();
        st.pop();
    }
    if(sum==n)
        return true;
    return false;
    }
};