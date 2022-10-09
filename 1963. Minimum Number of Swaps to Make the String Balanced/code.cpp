class Solution {
public:
    int minSwaps(string s) {
        int swapCount = 0 ;
        stack<char> st ;

        for(auto &c : s){
            if(c == '['){
                st.push(c) ;
            }
            else if(!st.empty() and c == ']'){
                st.pop() ;
            }
            else swapCount++ ;
        }

        return (swapCount+1)/2 ;
    }
};