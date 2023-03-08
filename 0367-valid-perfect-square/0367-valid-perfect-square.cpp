class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1 || num==4)
            return true;
        else
        {
            int start=0;
            int end=num;
            while(start<end)
            {
                long long mid=(start+end)/2;
                if(mid*mid==num)
                    return true;
                else if(mid*mid>num)
                    end=mid;
                else
                    start=mid+1;
            }
        }
        return false;
    }
};