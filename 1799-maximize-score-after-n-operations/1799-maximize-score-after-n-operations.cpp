class Solution {
public:
    unordered_map<int, int> table;
    inline int gcd(int x, int y){
        int r=x%y;
        return (r==0)?y:gcd(y, r);
    }
    int dfs(vector<int>&nums,  unordered_map<int, int>&mp,  int visited, int op , int n)
    {
        if (mp.count(visited)) return mp[visited]; 
            
        int maxScore = 0;
        bitset<14> v(visited);
        for (int i = 0; i < n-1; i++)
        {
            if (v[i]) continue;
            for (int j = i+1; j<n; j++)
            {
                if (v[j]) continue;
                
                int newVisited = visited;
                newVisited|=(1<<i); //mark i as visited
                newVisited|=(1<<j); //mark j as visited  
            //    cout<<v<<"--->"<<newVisited<<endl;
                int curr = op * table[(1<<i)+(1<<j)];
                int next = dfs(nums, mp, newVisited, op + 1, n);
                int total = curr + next;
                maxScore = max(maxScore, total);
            }
        }
        return mp[visited] = maxScore; //store the result
    }
    int maxScore(vector<int>& nums) 
    {
        int n = nums.size();

        for(int i=0; i<n-1; i++)
            for (int j=i+1; j<n; j++ ){
                table[(1<<i)+(1<<j)]=gcd(nums[i], nums[j]);                 
            }
      
        int visited=0;
        unordered_map<int, int> mp;
        int ans = dfs(nums, mp, visited, 1 ,n);
        return ans;    
    }
};