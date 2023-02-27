/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    bool checkval(vector<vector<int>>&grid, int x, int y, int n)
    {
        int val=grid[x][y];
        for(int i=x;i<x+n;i++)
        {
            for(int j=y;j<y+n;j++)
            {
                if(grid[i][j]!=val)
                    return false;
            }
        }
        return true;
    }
    void buildtree(vector<vector<int>>&grid, Node* root, int x, int y, int n)
    {
        if(checkval(grid,x,y,n))
        {
            root->isLeaf=true;
            root->val=grid[x][y];
        }
        else
        {
            root->isLeaf=false;
            root->val=1;
            
            root->topLeft=new Node();
            buildtree(grid,root->topLeft,x,y,n/2);
            
            root->topRight=new Node();
            buildtree(grid,root->topRight,x,y+n/2,n/2);
            
            root->bottomLeft=new Node();
            buildtree(grid,root->bottomLeft,x+n/2,y,n/2);
            
            root->bottomRight=new Node();
            buildtree(grid,root->bottomRight,x+n/2,y+n/2,n/2);
            
        }
    }
    Node* construct(vector<vector<int>>& grid) {
        Node* root=new Node();
        int n=grid.size();
        buildtree(grid,root,0,0,n);
        return root;
    }
};