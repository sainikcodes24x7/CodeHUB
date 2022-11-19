class Solution {
public:
   int angle(vector<int>&x, vector<int>&y, vector<int>&z){
        // (x2-x1)(y3-y1) - (y2-y1)(x3-x1) 
        return (y[0]-x[0])*(z[1]-x[1])-(y[1]-x[1])*(z[0]-x[0]);
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n=trees.size();
        if(n<=3)return trees;
        sort(trees.begin(), trees.end());
        //upper hull
        vector<vector<int>>up;
        up.push_back(trees[0]);
        up.push_back(trees[1]);
        for(int i=2; i<n; i++){
            int sz=up.size();
            while(sz>=2 and angle(up[sz-2],up[sz-1],trees[i])>0){
                up.pop_back();
                sz--;
            }
            up.push_back(trees[i]);
        }
        //lower hull
        vector<vector<int>>down;
        down.push_back(trees[trees.size()-1]);
        down.push_back(trees[trees.size()-2]);
        for(int i=n-3; i>=0; i--){
            int sz=down.size();
            while(sz>=2 and angle(down[sz-2],down[sz-1],trees[i])>0){
                down.pop_back();
                sz--;
            }
            down.push_back(trees[i]);
        }
        // remove duplicates
        for(auto x:down)up.push_back(x);
        sort(up.begin(), up.end());
        up.erase(unique(up.begin(), up.end()), up.end());
        return up;
    }
};