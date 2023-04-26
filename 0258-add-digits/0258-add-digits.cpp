class Solution {
public:
    int addDigits(int num) {
        int sum=0;
        while(num)
        {
            int x=num%10;
            sum+=x;
            num/=10;
            if(num==0 and sum/10 !=0)
            {
                num=sum;
                sum=0;
            }
        }
    return sum;
    }
};