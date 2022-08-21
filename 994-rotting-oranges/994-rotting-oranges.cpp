class Solution {
public:
    bool isFresh(int i, int j,vector<vector<int>>& grid, int n, int m)
    {
        if(i<n and j<m and i>=0 and j>=0 and grid[i][j]==1)
            return true;
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        // no of fresh oranges
        int fresh=0;
        
        //time taken to rot
        int time=0;
        
        //we declare a queue-pair to store rotten oranges index
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                //if we encounter a rotten orange we push it's index in the queue
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
                
                // else if the orange is fresh we increment the fresh counter
                else if(grid[i][j]==1)
                {
                    fresh++;
                }
                    
            }
        }
        
        //if all oranges are rotten no need to make any orange rotten anymore, so we return 0
        if(fresh==0)
            return 0;
        
        //apply BFS
        while(!q.empty())
        {
            int nsize=q.size();
            int temp=0;
            while(nsize--)
            {
                pair<int,int> p=q.front();
                q.pop();
                //x index of rotten orange in queue (top)
                int x1=p.first;
                //y index of rotten orange in queue (top)
                int y1=p.second;
                
                // four diagonally adj oranges which are fresh will rot
                int ax[4]={-1,1,0,0};
                int bx[4]={0,0,-1,1};
                
                for(int i=0;i<4;i++)
                {
                    //move to next adj (x,y) index of 2D array
                    int x=ax[i]+x1;
                    int y=bx[i]+y1;
                    
                    //now we check if the orange is fresh or rotten
                    
                    //if the orange is fresh and since the oranges are within 
                    //4-directionally adjacent to the same rotten orange we maintain a 
                    //counter and if the counter is positive we increment time
                    //also we make the orange rotten and push that rotten orange in queue
                    //so as to make it's effect fall on it's 4-directionally adjacent 
                    if(isFresh(x,y,grid,n,m))
                    {
                        temp++;
                        grid[x][y]=2;
                        q.push({x,y});
                    }
                }
            }
            //counter postive so timer incremented
            if(temp>0)
            {
                time++;
            }
        }
        
        // now we traverse the 2d array to check whether any orange remains unrotten or not
        // if any orange remains fresh we make time zero as our desired condition isn't                 //fulfilled
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                    time=0;
            }
        }
        if(time==0)
            return -1;
        else
            return time;
        
    }
};