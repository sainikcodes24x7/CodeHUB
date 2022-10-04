class Solution {
    public boolean isAnagram(String s, String t) {
        int cha[] = new int[26];
        for(int i=0;i<s.length();i++){
            cha[s.charAt(i)-97]++;
        }
        for(int i=0;i<t.length();i++){
            cha[t.charAt(i)-97]--;
        }
        for(int i=0;i<26;i++){
            if(cha[i]!=0){
                return false;
            }
        }
        return true;
    }
}
