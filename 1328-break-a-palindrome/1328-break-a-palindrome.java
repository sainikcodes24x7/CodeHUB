class Solution {
   char[] alpha = "abcdefghijklmnopqrstuvwxyz".toCharArray();
    public String breakPalindrome(String palindrome) {
        char[] arr = palindrome.toCharArray();
        int n = arr.length;
        if(n==1){
            return "";
        }
        for(int i=0;i<n/2;i++){
            if(arr[i]!='a'){
                arr[i] = 'a';
                return String.valueOf(arr);
            }
        }
        arr[n-1] = alpha[arr[n-1]-'a'+1];
        return String.valueOf(arr);
    }
}