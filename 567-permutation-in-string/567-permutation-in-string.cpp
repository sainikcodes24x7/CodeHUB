class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()==0 || s2.size()==0)
            return false;
        vector<int>hash1(26,0);
        vector<int>hash2(26,0);
        
        int n1=s1.length();
        int n2=s2.length();
        
        bool flag=false;
        
        for(int i=0;i<n1;i++)
        {
            hash1[s1[i]-'a']++;
        }
        
        int i=0,j=0;
        while(j<n2)
        {
            hash2[s2[j]-'a']++;
            
            if((j-i+1)<n1)
                j++;
            else{
                if(hash1==hash2)
                    flag=true;
                hash2[s2[i]-'a']--;
                i++;
                j++;
            }
        }
        return flag;
    }
};