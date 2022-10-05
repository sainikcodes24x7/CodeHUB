class Solution {
    int c=0;
    boolean flag=false;
    int max=0;
    public int longestCycle(int[] edges) {
        int n=edges.length;
        //creating the adjacency list
        List<List<Integer>> adj=new ArrayList<>();
        for(int i=0;i<n;i++){
            adj.add(new ArrayList<>());
        }
        for(int i=0;i<edges.length;i++){
            if(edges[i]!=-1){
                adj.get(i).add(edges[i]);
            }
        }
        //one for normal nodevisit
        int vis[]=new int[n];
        //check for cycle
        int dfsvis[]=new int[n];
        //for counting length of cycle
        int count[]=new int[n];
        flag=false;max=0;
        for(int i=0;i<n;i++){
           
            if(vis[i]==0){
                c=0;            
                dfs(i,vis,count,adj,dfsvis);
            }
        }
      //flag=false means no cycle exists
        return flag==false?-1:max;
    }
    public void dfs(int node,int vis[],int count[],List<List<Integer>> adj,int dfsvis[]){
        //we mark both vis and dfsvis as true
        vis[node]=1;
        dfsvis[node]=1;
        //traversing the adj list
        for(int it:adj.get(node)){
            //when node is not visited we increment the count by one and store it in count array
            if(vis[it]==0){
                c++;
                count[it]=c;
                //recursive call for other nodes
                dfs(it,vis,count,adj,dfsvis);
            }
            //when dfsvis is true cycle is detected we store the length of cycle and store it in  max and mark flag as true as cycle exists and break the loop
            
            else if(dfsvis[it]==1){
                c++;
                count[it]=c-count[it];
                max=Math.max(max,count[it]);
                flag=true;
             //   break;
            }
        }
        //when we come out of loop we mark again dfsvis as 0
        dfsvis[node]=0;
    }
}