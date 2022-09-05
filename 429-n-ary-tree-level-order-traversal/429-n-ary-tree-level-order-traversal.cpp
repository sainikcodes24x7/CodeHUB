/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root)
            return {};
        vector<vector<int>>ans;
        queue<Node*>pn;
        pn.push(root);
        while(pn.size()!=0)
        {
            int n=pn.size();
            vector<int>res;
            while(n)
            {
                auto top=pn.front();
                pn.pop();
                res.push_back(top->val);
                for(auto nbr:top->children)
                {
                    pn.push(nbr);
                }
                n--;
            }
            ans.push_back(res);
            //n--;
        }
        return ans;
    }
};