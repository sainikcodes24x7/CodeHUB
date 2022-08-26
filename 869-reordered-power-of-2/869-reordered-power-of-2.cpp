class Solution {
public:
    vector<string>array={"0112344778","011237","0122579",
"012356789","0124","0134449","0145678","01466788","0248",
"0368888","0469","1","112234778","11266777","122446",
"125","128","1289","13468","16","2","224588","23","23334455",
"234455668","23678","256","35566","4","46","8"};
    bool reorderedPowerOf2(int n) {
        string s= to_string(n);
        sort(s.begin(),s.end());
        return s==array[lower_bound(array.begin(),array.end(),s)-array.begin()];
    }
};