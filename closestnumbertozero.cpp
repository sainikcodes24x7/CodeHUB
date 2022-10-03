class Solution {
public:
    int findClosestNumber(vector<int>& arr) {
      int ans = INT_MAX;
        for(int i = 0; i < arr.size(); i++) {
            if(abs(arr[i]) < abs(ans)) {
                ans = arr[i];
            }
            else if(abs(arr[i]) == abs(ans) && arr[i] > ans) {
                ans = arr[i];
            }
        }
        return ans;
    }
};
