class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
       int n=digits.size();
    vector<int>kbc;
    int c=1;
    
    for(int i=n-1; i>=0; i--)
    {
        
        if(digits[i]==9 && c==1) 
            kbc.push_back(0);
		
		
        else kbc.push_back(digits[i]+c),
            c=0;
		
    }
    
	
    if(c==1) 
    kbc.push_back(c);
	
    reverse(kbc.begin(), kbc.end());
    return kbc;
        
    }
};
