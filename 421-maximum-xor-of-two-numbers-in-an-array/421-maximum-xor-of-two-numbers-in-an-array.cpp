class Solution {
public:
    struct Node{
        Node*links[2];
        
        bool ispresent(int idx){
            return links[idx]!=NULL;
        }
        Node* get(int ind)
        {
            return links[ind];
        }
        void put(int idx, Node*node)
        {
            links[idx]=node;
        }
    };
    
    class Trie{
        private:
        Node*root;
        public:
        Trie(){
            root=new Node();
        }
        void insert(int num)
        {
            Node* node=root;
            for(int i=31;i>=0;i--)
            {
                int bit=(num>>i)&1;
                if(!node->ispresent(bit))
                {
                    node->put(bit, new Node());
                }
                node=node->get(bit);
            }
        }
        int findmax(int num){
            Node* node=root;
            int maxnum=0;
            for(int i=31;i>=0;i--)
            {
                int bit=(num>>i)&1;
                if(node->ispresent(!bit))
                {
                    maxnum=maxnum|(1<<i);
                    node=node->get(!bit);
                }
                else
                {
                    node=node->get(bit);
                }
            }
            return maxnum;
        }
    };
    int findMaximumXOR(vector<int>& nums) {
        int n=nums.size();
        Trie t;
        for(int i=0;i<n;i++)
        {
            t.insert(nums[i]);
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,t.findmax(nums[i]));
        }
        return maxi;
    }
};