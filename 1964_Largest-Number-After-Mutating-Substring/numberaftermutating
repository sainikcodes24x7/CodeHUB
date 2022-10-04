class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        bool replace = false;
        for(int i=0; i<num.size(); i++) {
            char n = num[i] - '0';
            if (n < change[n] ) {
                num[i] = change[n] + '0';
                replace = true;
            }else if (n > change[n] && replace ) {
                break;
            }
        }
        return num;
    }
};
