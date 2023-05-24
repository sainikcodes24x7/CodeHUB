class Solution {
public:

    // Encodes a URL to a shortened URL.
    int val=256;
    unordered_map<string,string>mp;
    string encode(string longUrl) {
        //return longUrl;
        string res="http://tinyurl.com/"+ to_string(val);
        val++;
        mp[res]=longUrl;
        return res;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));