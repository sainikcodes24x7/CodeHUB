class Solution {
public:
    int subtractProductAndSum(int n) {
        
        int m,s=1,z,a,s1=0;
            m=n;
        a=n;
        while(m!=0)
        {
            int k=m%10;
            s=s*k;
            m=m/10;
            
        }
        while(a!=0)
        {
            z=a%10;
            s1=s1+z;
            a=a/10;
        }
        int res=s-s1;
       return res;
        
    }
    int main()
    {
        int n;
        cin>>n;
       int a= subtractProductAndSum(n);
        cout<<a<<endl;
        return 0;
        
        
        
    }
};