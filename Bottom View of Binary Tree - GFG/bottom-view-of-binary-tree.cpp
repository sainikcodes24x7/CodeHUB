//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


vector <int> bottomView(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
   vector<int> bottomView(Node *root) {
    // Create a map to store the vertical distance as key and node data as value.
    map<int, int> mp;
    
    // Create a queue for level order traversal.
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    
    while (!q.empty()) {
        // Get the front node and its vertical distance.
        auto top = q.front();
        Node* node = top.first;
        int dis = top.second;
        q.pop();
        
        // Update the map with the latest node data for the current vertical distance.
        mp[dis] = node->data;
        
        // Enqueue left child with a decreased vertical distance (dis-1).
        if (node->left) {
            q.push({node->left, dis - 1});
        }
        
        // Enqueue right child with an increased vertical distance (dis+1).
        if (node->right) {
            q.push({node->right, dis + 1});
        }
    }
    
    // Create a vector to store the final bottom view nodes.
    vector<int> ans;
    
    // Traverse the map and add node data to the vector.
    for (auto itr : mp) {
        ans.push_back(itr.second);
    }
    
    // Return the vector containing the bottom view nodes.
    return ans;
}

};

//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.bottomView(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}



// } Driver Code Ends