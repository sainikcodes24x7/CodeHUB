/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int,Node*>mp;
    Node* cloneGraph(Node* node) {
        if(!node)
            return NULL;
        if (mp[node->val])
            return mp[node->val];
        Node*t= new Node(node->val,node->neighbors);
        mp[node->val]=t;
        for(auto &x:t->neighbors)
            x=cloneGraph(x);
        return t;
    }
};