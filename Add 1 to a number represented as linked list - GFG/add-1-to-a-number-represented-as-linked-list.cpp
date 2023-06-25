//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node *reverse(Node *head)
    {
        Node* curr=head;
        Node* prev=NULL;
        Node* nnext=NULL;
        while(curr)
        {
            nnext=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nnext;
            
        }
        return prev;
    }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        Node* temp=reverse(head);
        //=head;
        Node* p=temp;
        while(p){
            if(p->data==9 and p->next==NULL){
                p->data=1;
                Node* newNode =new Node(0);
                newNode->next=temp;
                temp=newNode;
                p=p->next;
                
            }
            else if(p->data==9){
                p->data=0;
                p=p->next;
            }
            else{
                p->data=p->data+1;
                break;
            }
        }
        head=reverse(temp);
        return head;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends