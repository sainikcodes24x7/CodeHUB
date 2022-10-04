class Solution {
public:
    int xorAllNums(vector<int>& n2, vector<int>& n1) {
        int s1=n1.size(); // size of n1
        int s2=n2.size(); // size of n2
        int ans=0; // initially, ans=0 (property: 0^X=X)
        if(s2 % 2){ // if s2 is odd, then one occurence of elements of n1 will contribute to the answer
            for(int &i:n1)
                ans ^= i;
        }
        if(s1 % 2){ // similarly, if s1 is odd, then one occurence of elements of n2 will contribute to the answer
            for(int &i:n2)
                ans ^= i;
        }
        return ans;
    }
};