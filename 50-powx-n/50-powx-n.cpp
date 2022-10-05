class Solution {
public:
    double myPow(double x, int n) {
        if(x==1)
            return 1;
        if(x==-1)
            return (n%2==0)?1:-1;
        if(n==INT_MIN)
            return 0;
        double ans=1;
        if(n>0){
        for(int i=0;i<n;i++)
        {
            ans*=x;
        }
        }
        else if(n<0)
        {
           for(int i=0;i<abs(n);i++)
        {
            ans/=x;
        } 
        }
        else
            return 1;
        return ans;
    }
};