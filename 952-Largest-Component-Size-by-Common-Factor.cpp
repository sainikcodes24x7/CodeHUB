class Solution {
public:
    int par[100005];
    int rank[100005];
    
    void makeSet(){
        for(int i = 0; i<100005; i++){
            par[i] = i;
            rank[i] = 0;
        }
        return ;
    }
    
    int findPar(int u){
        if(par[u] == u) return u;
        return par[u] = findPar(par[u]);
    }
    
    void unionn(int u, int v){
        u = findPar(u);
        v = findPar(v);
        if(u==v) return;
        if(rank[u] > rank[v]) {
            par[v] = u;
        }
        else if(rank[v] > rank[u]){
            par[u] = v;
        }
        else{
            rank[u]++;
            par[v] = u;
        }
        return;
    }
    
    int largestComponentSize(vector<int>& nums) {
        makeSet();
        for(int curr : nums){
            for(int i = 2; i<=sqrt(curr); i++){
                if(curr%i==0){
                    unionn(curr, i);
                    unionn(curr, curr/i);
                }
            }
        }
        map<int, int> mp;
        int ans = 1;
        for(int i = 0; i<nums.size(); i++){
            ans = max(ans, ++mp[findPar(nums[i])]);
        }
        return ans;
    }
};
