class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        // to ensure that we can find the words efficiently
        set<string>wordset;
        for(auto it:wordList)
        {
            wordset.insert(it);
        }
        // creating a queue pair which shall store current string along with steps required
        // to change  beginword to current one with min no of steps
        
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                pair<string,int>top=q.front();
                q.pop();
                
                //if we find the current string is endWord we will return the steps
                if(top.first ==endWord)
                    return top.second;
                
                //now we will iterate on all the indices of str and change it to all possible characters(a-z)
				//and see if the string that we made is in our set or not, if it is we increment the step and
				//push it in our queue
                for(int i=0;i<top.first.length();i++)
                {
                    char orig= top.first[i];
                    for(char c='a';c<='z';++c)
                    {
                        if(c==orig)
                            continue;
                        top.first[i]=c;
                        if(wordset.count(top.first)){
                            q.push({top.first,top.second+1});
                            wordset.erase(top.first);
                        }
                    }
                    top.first[i]=orig;
                }
            }
        }
        return 0;
    }
};