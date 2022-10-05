class Solution {
private:
    void print(vector<vector<int>>& vv) {
        cout << "[";
        int i = 0;
        for(; i<vv.size()-1; i++) {
            cout << "[" << vv[i][0] << "," << vv[i][1] << "],";
        }
        cout << "[" << vv[i][0] << "," << vv[i][1] << "]]" << endl;
    }
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        

        for(int i=0; i<queries.size(); i++) { 
            queries[i].push_back(i);
        }
        
        // sorted the rooms by size by descending order, because query the minimal size.
        auto sort_by_size_desc =  [&](vector<int>& lhs, vector<int>&rhs) {
            if (lhs[1] != rhs[1] ) return lhs[1] > rhs[1];
            return lhs[0] < rhs[0];
        };
        sort(rooms.begin(), rooms.end(), sort_by_size_desc);
        sort(queries.begin(), queries.end(), sort_by_size_desc);
        //print(rooms);
        //print(queries);
        
        vector<int> result(queries.size(), -1);
        set<int> ids;
        int i = 0;
        for( auto& q: queries) {
            int preferId = q[0];
            int minSize = q[1];
            int idx = q[2];
            for (;i < rooms.size() && rooms[i][1] >= minSize; i++) {
                ids.insert(rooms[i][0]);
            }
            if (ids.size() <= 0 ) continue;
            auto it = ids.lower_bound(preferId); 
            
            int id1 = (it == ids.begin() ? -1 : *(prev(it)));
            int id2 = (it == ids.end() ? -1 : *it);
            
            if (id1 == -1 || id2 == -1) {
                result[idx] = max(id1, id2);
            }else{
                result[idx] = abs(preferId - id1) <= abs(preferId - id2) ? id1 : id2;
            }
            
        }
        return result;
}
}
