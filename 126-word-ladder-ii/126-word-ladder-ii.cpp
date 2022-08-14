class Solution {
public:
   vector<string> g_words(string a, unordered_map<string,int> &m){
vector<string> ans;

for(int i=0;i<a.size();i++){
    string temp =a;
    for(char j='a';j<='z';j++){
        
        temp[i] = j;
        if(temp==a) continue;
        if(m.find(temp)!=m.end()){
            ans.push_back(temp);
        }
    }
}
return ans;
}

void backtrack(string start,string vertex,unordered_map<string,vector<string>> &adj_list,vector<string> &path,vector<vector<string>> &ans){

if(vertex==start){
    path.push_back(vertex);
    vector<string> temp = path;
    reverse(temp.begin(),temp.end());
    ans.push_back(temp);
    path.pop_back();
    return;
}
path.push_back(vertex);
for(auto i:adj_list[vertex]){

    
    backtrack(start,i,adj_list,path,ans);
    

}
path.pop_back();
return;

}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    string start = beginWord;
    string end = endWord;
    vector<string> dict = wordList;
    unordered_map<string,int> m;
unordered_map<string,int> level;

unordered_map<string,vector<string>> adj_list;

vector<vector<string>> ans;
vector<string> path;

for(int i=0;i<dict.size();i++){
    m[dict[i]] = 0;
}


queue<string> q;
q.push(start);
m[start] =1;
level[start] =1;


while(!q.empty()){
    
    int s = q.size();
    while(s--){
        
        string curr = q.front();
        q.pop();
        
        for(auto child : g_words(curr,m)){

            if(m[child]==0){
                
                q.push(child);
                m[child]++;
                level[child] = level[curr] +1;
                
                adj_list[child].push_back(curr);
            }
            else{
                if(level[child]==level[curr]+1){
                    
                    adj_list[child].push_back(curr);
                }
            }
        } 
        
    }
}

backtrack(start,end,adj_list,path,ans);

return ans;
}
};