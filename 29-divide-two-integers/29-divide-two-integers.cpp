class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN and divisor==-1) return INT_MAX;
        bool sign = ((dividend>=0)==(divisor>=0)) ?true :false;
        long int res=0;
        long int ldividend=abs(dividend);
        long int ldivisor=abs(divisor);
        while((ldividend-ldivisor)>=0){
            int cnt=0;
            while(ldividend>=(ldivisor<<cnt))cnt++;
            res+=(1<<(cnt-1));
            ldividend-=ldivisor<<(cnt-1);
        }
        if(res>INT_MAX) return (sign)?INT_MAX:INT_MIN;
        return (sign)?res:-res;
    }
};