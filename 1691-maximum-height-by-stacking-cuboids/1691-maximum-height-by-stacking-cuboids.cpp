class Solution {
public:
    bool check (vector<int>&a, vector<int>&newbox)
    {
        if(a[0]>=newbox[0] and a[1]>=newbox[1] and a[2]>=newbox[2])
            return true;
        return false;
    }
    int solve(int n, vector<vector<int>>&a)
    {
        vector<int>curRow(n+1,0);
        vector<int>nextrow(n+1,0);
        
        for(int curr=n-1;curr>=0;curr--)
        {
            for(int prev=curr-1;prev>=-1;prev--){
                
                //take
                int take=0;
                if(prev==-1 || check(a[curr],a[prev]))
                    take=a[curr][2]+nextrow[curr+1];
                
                //exclude
                int nottake=0+nextrow[prev+1];
                curRow[prev+1]=max(take,nottake);
            }
            nextrow=curRow;
        }
        return nextrow[0];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        // sort all dimentions for every cubiod
        
        for(auto &a:cuboids)
        {
            sort(a.begin(),a.end());
        }
        
        // sorting all cubiods based on width and length
        sort(cuboids.begin(),cuboids.end());
        
        //use LIS logic
        return solve(cuboids.size(),cuboids);
    }
};