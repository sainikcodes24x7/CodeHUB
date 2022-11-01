class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
         int n=grid.size();
        int m=grid[0].size();
        vector<int> v(m); // m beacuse answer will be of m columns 
        for(int j=0;j<m;j++){ //quering hose m col
            int curr_pos=j;//curr_pos==col
            int next_pos=-1;
            
            
            for(int i=0;i<n;i++){  //will go down so playing with row 
                next_pos=curr_pos+grid[i][curr_pos];  // next_p=>value of that grid +cur 
                if(next_pos<0||next_pos>=m||grid[i][curr_pos]!=grid[i][next_pos]){ //checking condition when ball will not //come out of cell successfully 
				//1.out of valid wall 
				//2.when successive grid have opposing value that will make a riff 
                    curr_pos=-1;// in such a case make cur_pos negative 
                    break; // no operation break
                }
                curr_pos=next_pos;//update curr_pos
            }
            v[j]=curr_pos;//push in vector array
            
        }
        
        return v;
    }
};