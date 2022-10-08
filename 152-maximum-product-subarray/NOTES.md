class Solution {
public:
int maxProduct(vector<int>& nums) {
int n=nums.size();
int start=1,end=1;
int i=0,j=n-1;
int ans=INT_MIN;
while(i<n and j>=0)
{
start =start *nums[i];
end=end*nums[j];
ans=max(ans,max(start,end));
if(nums[i]==0){
start=1;
}
if(nums[j]==0){
end=1;
}
i++;
j--;
}
return ans;
}
/*
int  start=1,end=1;
int ans=INT_MIN;
int i=0,j=n-1;
while(i<n && j>=0){
start*=arr[i];
end*=arr[j];
ans=max(ans,max(start,end));
if(arr[i]==0){
start=1;
}
if(arr[j]==0){
end=1;
}
i++;
j--;
}
return ans;
}
*/
};