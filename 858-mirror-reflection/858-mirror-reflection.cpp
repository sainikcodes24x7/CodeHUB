class Solution {
public:
    int mirrorReflection(int p, int q) {
         int left = 0;
        int right = 0;
        int toggle = 0;
        int cur = 0;
        while(1) {
            left = cur*toggle + q;
            right = cur*(toggle^1) + q;
            cur += q;
            toggle^=1;
            if(toggle == 0 && left % p == 0) {
                if(left < p)
                    continue;
                return 2;
            }
            else if (toggle == 1) {
                if(right < p)
                    continue;    
                if(right % (2*p) == 0)
                    return 0;
                else if(right % (p) == 0)
                    return 1;
            }
        }
        return 0;
    }
};