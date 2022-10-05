class Solution {
public:
    string removeStars(string s) {
        stack<char> stk; // stack to store the rightmost character
        for(char& c:s){
            if(c=='*'){
                stk.pop(); // delete the rightmost character to my left
            }else
                stk.push(c); // otherwise push the char to stack
        }
        string res;
        // pop all chars in stack, and append to a string
        while(!stk.empty()){
            res += stk.top();
            stk.pop();
        }
        // reverse the string, as stack follows LIFO order
        reverse(res.begin(), res.end());
        // return the result
        return res;
    }
};
