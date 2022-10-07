class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        int max=-1,temp=0;
        for(int i=n-1;i>=0;i--)
        {
            if(arr[i]>max)
            {
                temp=arr[i];
            }
            else
            {
                temp=max;
            }
            arr[i]=max;
            max=temp;
        }
        return arr;
    }
};