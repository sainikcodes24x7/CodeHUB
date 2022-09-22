class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size();
        
        int i=0,j=n-1;
        int diff=0;
        while(colors[i]==colors[j])
            j--;
        diff=j-i;
        j=n-1;
        while(colors[i]==colors[j])
            i++;
        diff=max(diff,j-i);
        return diff;
    }
};