class Solution {
public:
    int convertTime(string current, string correct) {
        string starthr=(current.substr(0,2));
        string startmin=(current.substr(3,5));
        int start=stoi(starthr)*60+stoi(startmin);
        
        string endhr=(correct.substr(0,2));
        string endmin=(correct.substr(3,5));
        int end=stoi(endhr)*60+stoi(endmin);
        
        int diff=end-start;
        int op=0;
        
        op+=diff/60;
        diff=diff%60;
        
        op+=diff/15;
        diff=diff%15;
        
        op+=diff/5;
        diff=diff%5;
        
        return op+diff;
    }
};