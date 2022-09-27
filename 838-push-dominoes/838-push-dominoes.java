class Solution {
    public String pushDominoes(String dominoes) {
        int n=dominoes.length();
        char []dom=dominoes.toCharArray();
        int []forces= new int[n];
        int force=0;
        for(int i=0;i<n;i++)
        {
            if(dom[i]=='R')
            {
                force=n;
            }
            else if(dom[i]=='L')
            {
                force=0;
            }
            else
            {
                force=Math.max(force-1,0);
            }
            forces[i]+=force;
        }
        force=0;
        
        for(int i=n-1;i>=0;i--)
        {
             if(dom[i]=='L')
            {
                force=n;
            }
            else if(dom[i]=='R')
            {
                force=0;
            }
            else
            {
                force=Math.max(force-1,0);
            }
            forces[i]-=force;
        }
        StringBuilder str = new StringBuilder();
        for(Integer itr:forces)
        {
            if(itr>0)
                str.append('R');
            else if(itr<0)
                str.append('L');
            else
                str.append('.');
        }
        return str.toString();
    }
}