class Node{
    Node links[]=new Node[26];
    boolean flag=false;
    Node(){}
    boolean containsKey(char ch){
        return (links[ch-'a']!=null);
    }
    Node get(char ch){
        return links[ch-'a'];
    }
    void put(char ch,Node node){
        links[ch-'a']=node;
    }
    void setEnd(){
        flag=true;
    }
    boolean isEnd(){
        return flag;
    }
}
class Trie{
    Node root;
    Trie(){
        root=new Node();
    }
    public void insert(String word){
        Node node=root;
        for(int i=0;i<word.length();i++){
            if(!node.containsKey(word.charAt(i))){
                node.put(word.charAt(i),new Node());
            }
            node=node.get(word.charAt(i));
        }
        node.setEnd();
    }
    public boolean search(String word){
        Node node=root;
        for(int i=0;i<word.length();i++){
            node=node.get(word.charAt(i));
            if(!node.isEnd()){
                return false;
            }
        }
        return node.isEnd();
    }
}
class Solution {
    public String longestWord(String[] words) {
        Trie obj=new Trie();
        for(String x:words){
            obj.insert(x);
        }
        String t1="";
        for(String x:words){
            if(obj.search(x)){
                if(x.length()>t1.length()){
                    t1=x;
                }
                else if(x.length()==t1.length() && x.compareTo(t1)<0){
                    t1=x;
                }
            }
        }
        return t1;
    }
}