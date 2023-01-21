class Solution {
public:
    bool check(string a)
    {
        int n=a.size();
        if(n==1)
            return true;
        if(n>3 || a[0]=='0')
            return false;
        int val=stoi(a);
        if(val>255)
            return false;
        return true;
    }
    vector<string> restoreIpAddresses(string s) {
        int n=s.size();
        vector<string>ans;
        if(n>12)
            return ans;
        for(int i=1;i<=3;i++)
        {
            for(int j=1;j<=3;j++)
            {
                for(int k=1;k<=3;k++)
                {
                    if(i+j+k<n and i+j+k+3>=n)
                    {
                        string a=s.substr(0,i);
                        string b=s.substr(i,j);
                        string c=s.substr(i+j,k);
                        string d=s.substr(i+j+k);
                        
                        if(check(a) && check(b) and check(c) and check(d))
                            ans.push_back(a+"."+b+"."+c+"."+d);
                    }
                }
            }
        }
        return ans;
    }
};