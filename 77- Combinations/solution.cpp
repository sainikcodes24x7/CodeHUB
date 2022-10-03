class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
		vector<int> v;
		function<void(int,int)> recur=[&](int x,int k){
			if(k==0) {
				res.push_back(v);
				return;
			}
			for(int i=x;i<=n;i++) {
				v.push_back(i);
				recur(i+1,k-1);
				v.pop_back();
			}
		};
		recur(1,k);
		return res;
        
    }
};