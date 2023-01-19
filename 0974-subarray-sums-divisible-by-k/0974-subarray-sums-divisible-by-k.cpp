class Solution {
public:
    //This function return the mod of negative and positive integer with k;
    //In c++ when we have neg number mod k then we get that negative number so 
    //to make all the number positive and less than k we are taking mod with k.
    int negMod(int n,int mod){
        
        if(n<0){//if our number is negative 
            n=abs(n)%mod;
            return (-n+mod)%mod;
        }
        //if our number is postive 
        return n%mod;
    }
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        //now we are having two variables cur and ans in cur variable we are
        //storing the cur sum mod k
        //in ans we are storing the occurance of subarray which is divisible by k
        int cur=0,ans=0;
        unordered_map<int,int>m;
        //initially our cur sum is empty so we have make our map of 0 to increase to 1.
        m[0]++;
        
        for(int num:nums){
            
            cur=(cur+negMod(num,k))%k;//adding the mod value to cur
            
            if(m.count(cur)){//if we have cur number in the map so there must be an subarray 
                //between them with sum =0
                ans+=m[cur];
                
            }
            //incrementing the cur value
            m[cur]++;
        }
        //return the ans
        return ans;
    }
};