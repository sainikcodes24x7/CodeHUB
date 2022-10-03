class Solution {
public:
    int myAtoi(string s) {
        bool sign = trim_helper(s);  //trim the s and let it only left for number.
        int length = s.size();
        unsigned long long int result= 0;
        for(unsigned int i = 0; i < length; i++)
        {
            if(result + (int(s[i])-48) * pow(10, length - (i+1)) > pow(2, 31))
            {
                result = pow(2, 31);
                break;
            }
            result += (int(s[i])-48) * pow(10, length - (i+1));        //use ascii value to turn it to integer.   
        }
        
        if(sign == false)
        {
            return result*(-1);
        }
        else if(result == pow(2, 31))
        {
            return result-1;
        }
        return result;
    }
    
    
    bool trim_helper(string& s){
        int start = 0;
        bool sign = true;
        for(int j = 0; j < s.size(); j++)            //we can deal with that problem with finding the starting index and substringing
        {
            if(s[j] != ' ')
            {
                start = j;
                break;
            }
        }
        s=s.substr(start);                          //once we find the start, then once we reach a non-digit we stopped. 
        
        if(s[0] == '-')
        {
            sign = false;
            s.erase(s.begin()+0);
        }
        else if(s[0] == '+')
        {
            s.erase(s.begin()+0);
        }
        
        for(int i = 0; i < s.size(); i++)
        {
            if((int(s[i]) < 48)||(int(s[i]) > 57))        //if this is not a number. 
            {
                s.erase(s.begin() + i, s.end());                     //erase the index at that part if it is not number.
                break;   
            }
        }
        
        return sign;
    }
};
