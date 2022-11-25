class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
          int n = arr.size(), mod = 1e9 + 7;

        stack<pair<int, int>> st;
        vector<int> pse(n, -1);
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() and st.top().first > arr[i])
                st.pop();

            if (!st.empty())
                pse[i] = st.top().second;

            st.push({arr[i], i});
        }

        while (!st.empty())
            st.pop();

        vector<int> nse(n, n);
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() and st.top().first >= arr[i])
                st.pop();

            if (!st.empty())
                nse[i] = st.top().second;

            st.push({arr[i], i});
        }

        long ans = 0;
        for (int i = 0; i < n; i++)
        {
            long left = i - pse[i];
            long right = nse[i] - i;
            ans = (ans + left * right * arr[i]) % mod;
        }

        return ans;

    }
};