/* My main Logic is
If a number is 0 or ending with a 0, then i wont get the same number after double reversal.
In this case, i will return false.Remaining all cases, i return true.
Example: Number=2110.
         After first reversal, my number is 112.
         After double reversal, my number is 211, which is not equal to 2110*/
class Solution {
public:
    bool isSameAfterReversals(int num) {
        if(num%10==0&&num!=0) return false;
        else return true;
    }
};
