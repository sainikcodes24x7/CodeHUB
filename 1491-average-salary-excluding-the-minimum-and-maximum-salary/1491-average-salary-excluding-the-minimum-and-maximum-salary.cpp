class Solution {
public:
    double average(vector<int>& s) {
    return (reduce(begin(s), end(s), 0.) - *min_element(begin(s), end(s)) 
        - *max_element(begin(s), end(s))) / (s.size() - 2);
    }
};