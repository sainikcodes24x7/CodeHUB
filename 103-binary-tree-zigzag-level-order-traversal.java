class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        Deque<TreeNode> q = new LinkedList<>();
        List<List<Integer>> result = new LinkedList<>();
        q.offer(root);
         //List<List<Integer>> x = new LinkedList<>();
        if(root == null) return result;
        int flag = 0;
        while(!q.isEmpty()) {
            int s = q.size();
            Deque<Integer> sub = new LinkedList<>();
            for(int i=0; i<s; i++) {
                if(q.peek().left != null) 
                    q.offer(q.peek().left);
                if(q.peek().right != null)
                    q.offer(q.peek().right);
                if(flag % 2 == 0)
                    sub.offer(q.poll().val);
                else
                    sub.offerFirst(q.poll().val);
                //flag++;
            }
            Iterator<Integer> it = sub.iterator();
            List<Integer> sub2 = new LinkedList<>();
            while (it.hasNext()) {
                sub2.add(it.next());
            }
            result.add(sub2);   
            flag++;
        }
        return result;
    }
}
