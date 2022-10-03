//https://leetcode.com/contest/weekly-contest-313/problems/minimize-xor/
class Solution {
    public int minimizeXor(int num1, int num2) {
         int a1=countSetBits(num1);
        int a2=countSetBits(num2);
        
        if(a1==a2)return num1;
        int get=(int)Math.pow(2,a2)-1;
        
        if(num1<get)return get;
        else{
            int x=num1,x1=num1;
            while(a2!=countSetBits(x)){
                x++;
            }
            while(x1>1 && a2!=countSetBits(x1)){
                x1--;
            }
            if((x^num1)<(x1^num1)){
                return x;
            }
            else{
                return x1;
            }
        }
    }
    public int countSetBits(int n)
    {
        int count = 0;
        while (n > 0) {
            n &= (n - 1);
            count++;
        }
        return count;
    }
}