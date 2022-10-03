class Solution {
public:
    int commonFactors(int a, int b) {
        int c= min(a,b),count=0;
        for(int i=1;i<=c;++i){
            if((a%i==0)&&(b%i==0)) count+=1;
        }
        return count;
    }
};
