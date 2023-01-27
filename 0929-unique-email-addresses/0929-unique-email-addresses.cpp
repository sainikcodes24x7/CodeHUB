class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string>st;
        for(auto &itr:emails)
        {
            string email;
            for(auto c:itr)
            {
                if(c=='+' || c=='@')
                    break;
                if(c=='.')
                    continue;
                email+=c;
            }
            email+=itr.substr(itr.find('@'));
            st.insert(email);
        }
        
        return st.size();
    }
    
};