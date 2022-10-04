class Solution{
    public int findContentChildren(int [] g, int [] s){
        Array.sort(g);
        Array.sort(s);
        int a_p = 0;
        int b_p = 0;

        while(a_p < g.length && b_p < s.length) {
            if(g[a_p] <= s[b_p]){
                a_p++;
                b_p++;
            } else {
                b_p++;
            }
        }
        return a_p;

    }
}