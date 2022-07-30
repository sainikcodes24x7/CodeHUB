class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n=arr.size();
        vector<int>ps(n);
        vector<int>ns(n);
        stack<int>st;
        
        // finding ps
        for(int i=0;i<n;i++){
        while(!st.empty() && arr[i]<=arr[st.top()]){
            st.pop();
        }
        if(st.empty()){
            ps[i]=-1;
        }
        else{
            ps[i]=st.top();
        }
        st.push(i);
      }
        while(!st.empty()){
            st.pop();
        }
        // finding ns
        for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[i]<=arr[st.top()]){
            st.pop();
        }
        if(st.empty()){
            ns[i]=n;
        }
        else{
            ns[i]=st.top();
        }
        st.push(i);
      }
        int maxarea=INT_MIN;
        for(int i=0;i<n;i++){
            maxarea=max(maxarea,((ns[i]-ps[i]-1)*arr[i]));
        }
        return maxarea;
    }
};