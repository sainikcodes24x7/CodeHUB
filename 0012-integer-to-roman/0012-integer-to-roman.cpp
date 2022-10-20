class Solution {
public:
    string intToRoman(int num) {
        string ans;
        //vector<pair<int,char>>arr={{1,'I'},{4,'IV'},{5,'V'},{9,'IX'},{10,'X'},{40,'XL'},{50,'L'},
                                //   {90,'XC'},{100,'C'},{400,'CD'},{500,'D'},{900,'CM'},{1000,'M'}};
        
        string roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        for(int i=0;num!=0;i++)
        {
            while(num>=val[i])
            {
                num-=val[i];
                ans+=roman[i];
            }
        }
        return ans;
    }
};