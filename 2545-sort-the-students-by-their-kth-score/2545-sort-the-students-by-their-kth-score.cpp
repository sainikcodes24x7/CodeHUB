int p;
  bool comp (vector<int>&a, vector<int>&b)
    {
        return a[p]>b[p];
    }
class Solution {
public:
    
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        p=k;
        //vector<int>val;
        
        
            sort(score.begin(),score.end(),comp);
        
         
        return score;
    }
};