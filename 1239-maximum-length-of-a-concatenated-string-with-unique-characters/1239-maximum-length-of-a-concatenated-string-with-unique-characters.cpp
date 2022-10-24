class Solution {
public:
    int maxi=-1;
    int isRepeating(string s)
    {
        unordered_set<char>st;
        for(auto itr:s)
        {
            if(st.find(itr)!=st.end())
                return 1;
            st.insert(itr);
        }
        return 0;
    }
    void maxlengthhelper(int itr, vector<string>&arr, string s, int size)
    {
        if(isRepeating(s))
            return;
        if(itr==size)
        {
            int n=s.length();
            maxi=max(maxi,n);
            return;
        }
        //checking in the next string 
        maxlengthhelper(itr+1,arr,s+arr[itr],size);
        //checking in the same string
        maxlengthhelper(itr+1,arr,s,size);
    }
    int maxLength(vector<string>& arr) {
        int n=arr.size();
        maxlengthhelper(0,arr,"",n);
        return maxi;
    }
};