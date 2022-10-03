/*
The main logic of my code is
If a number is 0 or ends with a 0, then i will return false. Remaining all cases, i return true.
Because if a number ends with 0, after double reversal i wont get same number.

Example:
if Number is 2110. 
After first reversal, it will be 112.
After double reversal, it will be 211 which is not equal to 2110.
*/
class Solution {
public:
    bool isSameAfterReversals(int num) {
        if(num%10==0&&num!=0) return false;
        else return true;
    }
};
