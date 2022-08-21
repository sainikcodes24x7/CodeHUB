class Solution {
public:
    int check(string &str, string stamp)
    {
        int n=str.length();
        for(int i=0;i<n;i++)
        {
            int j=0,temp=i;
            bool flag=false;
            while(temp<n and j<stamp.length() and (str[temp]=='*' || str[temp]==stamp[j]))
            {
                if(str[temp]==stamp[j])
                    flag=true;
                temp++;
                j++;
            }
            
            if(j==stamp.length() and flag==true)
            {
                for(int k=0;k<stamp.length();k++)
                {
                    str[i+k]='*';
                }
                return i;
            }
            
        }
        return n;
    }
    
    
    vector<int> movesToStamp(string stamp, string target) {
        vector<int>ans,res;
        string str=target;
        string dummy(target.length(),'*');
        
        //iterate till we encounter stars in str
        while(str!=dummy)
        {
            int value=check(str,stamp);
           
            //if stamping done successfully we return result
            if(value==str.length())
                return res;
            
            ans.push_back(value);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};