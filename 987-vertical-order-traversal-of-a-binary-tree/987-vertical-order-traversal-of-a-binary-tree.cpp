/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    static bool comp(pair<int,int> a, pair<int,int> b){ //for multiples nodes in same row or column sort these by their values
        if(a.first==b.first)
            return a.second<=b.second;
        else
            return a.first<b.first;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        map<int,vector<pair<int,int>>> m;
        int j=1;
        while(!q.empty()){//BFS
            int n=q.size();
            for(int i=0 ; i<n ; i++){
            auto p=q.front();
            q.pop();
            TreeNode* top=p.first;
            int lev=p.second;
            if(top->left){
                q.push({top->left,lev-1});
            }
            if(top->right){
                q.push({top->right,lev+1});
            }
            m[lev].push_back({j,top->val});   
            }
            j++;
        }
        for(auto a:m){
            sort(a.second.begin(),a.second.end(),comp);
            vector<int> temp;
            for(auto l:a.second){
                temp.push_back(l.second);
            }
            ans.push_back(temp);
            temp.clear();
        }
        return ans;
    }
};