class Solution {
    public String makeGood(String s) {
        List<Character> list = new ArrayList<>();
        for(Character c:s.toCharArray()){
            list.add(c);
        }
        for(int i=0; i<list.size()-1; i++){
            
            
            // debugging going on
            // System.out.println("fresh value of i is "+i+" and characters are "+list.get(i)+ " and " +list.get(i+1)+"  and their difference is "+Math.abs((int)(list.get(i)-list.get(i+1))));
            
            
            if(Math.abs((int)(list.get(i)-list.get(i+1)))==32){
                list.remove(i);
                list.remove(i);
                i=-1;
            }
			// debugging going on
            // System.out.println("value of i is "+i+" while exiting internal check");
        }
        String ans = "";
        for(Character c:list){
            ans+=c;
        }
        return ans;
    }
}