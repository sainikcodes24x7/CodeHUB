class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>arr(n+2,0);
        for(int i=0;i<bookings.size();i++)
        {
            arr[bookings[i][0]]+=bookings[i][2];
            arr[bookings[i][1]+1]-=bookings[i][2];
        }
        for(int i=1;i<n+2;++i)
        {
            arr[i]+=arr[i-1];
        }
        vector<int>res;
        for(int i=1;i<=n;i++)
        {
            res.push_back(arr[i]);
        }
        return res;
    }
};