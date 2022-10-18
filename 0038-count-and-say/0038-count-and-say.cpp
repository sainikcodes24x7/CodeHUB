class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        string curr=countAndSay(n-1);
        string res="";
        int count=1;
        char ch=curr[0];
        for(int i=1;i<curr.size();i++)
        {
            if(ch==curr[i]){
                count++;
            }
            else{
                res+=to_string(count);
                res+=ch;
                ch=curr[i];
                count=1;
            }
        }
        res+=to_string(count);
        res+=ch;
        return res;
    }
};