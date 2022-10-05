#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
#include <string>
#define ft first 
#define se second 
#define PB push_back
#define MP make_pair
#define nline "\n"
#define ll long long
// given n pairs of parentheses , write a function to generate all combinations of well-formed parentheses.

using namespace std;
vector<string>valid;
void generate(string &s,int open, int close){
    if(open== 0 && close==0){
        valid.PB(s);
        return ;
    }
    if(open>0){
        s.PB('(');
        generate(s,open-1,close);
        s.pop_back();
    }
    if(close>0){
        if(open<close){
            s.PB(')');
            generate(s,open,close-1);
            s.pop_back();
        }
    }
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    string s;
    cin>>s;
    generate(s,n,n);
    for(auto ele: valid){
        cout<<ele<<endl;
    }
}
