
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
      //initial my ans=0
        int ans=0,i;
        for(i=0;i<operations.size();i++){
          // if x is preincrement(X++) or postincrement(X++), i will increase my ans by adding 1
            if(operations[i]=="++X"||operations[i]=="X++") ans=ans+1;
          //else decrement my ans by adding -1
            else ans=ans-1;
        }
      //finally return my ans;
        return ans;
    }
};
