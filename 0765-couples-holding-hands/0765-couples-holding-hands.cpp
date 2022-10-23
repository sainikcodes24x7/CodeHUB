class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        //store the indices in a frequency/hashmap
        int n=row.size();
        int count=0;
        
        
        vector<int>hash(n,0);
        
        for(int i=0;i<n;i++)
        {
            hash[row[i]]=i;
        }
        //for odd number bitwise xor with 1 decrements it by 1
        //for even number bitwise xor with 1 increments it by 1
        
        for(int i=0;i<n;i+=2)
        {
            int first=row[i];
            int second=first^1;
            if(hash[second]!=i+1)
            {
                count++;
                //required index values have been swapped and the couples are placed together
                int idx=hash[second];
                swap(row[i+1],row[idx]);
                //now their address stored in hashmaps has to be updated also
                hash[row[i+1]]=i+1;
                hash[row[idx]]=idx;
            }
        }
        return count;
    }
};