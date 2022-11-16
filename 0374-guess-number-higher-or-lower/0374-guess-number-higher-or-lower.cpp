/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int start=1;
        int end=n;
        int mid=start+(end-start)/2;
        while(start<end)
        {
            int x=guess(mid);
            if(x==1)
                start=mid+1;
            else if(x==-1)
                end=mid;
            else
                return mid;
            
            mid=start+(end-start)/2;
        }
        return start;
    }
};