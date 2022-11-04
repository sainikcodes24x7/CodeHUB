class Solution {
   boolean isvowal(char ch)
{
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')
        return true;
    return false;
}

public String reverseVowels(String s) {
    
    char[] ch= s.toCharArray();
    int j=ch.length-1;
    int i=0;
    
    while(i<j)
    {
        if(isvowal(ch[i]) && isvowal(ch[j]))
        {
            char temp=ch[i];
            ch[i]=ch[j];
            ch[j]=temp;
            i++;
            j--;
        }
        else if(isvowal(ch[i]) && !isvowal(ch[j]))
            j--;
        else if(!isvowal(ch[i]) && isvowal(ch[j]))
            i++;
        else{
            i++;
            j--;
        }
    }
    
    return new String(ch);
}
}