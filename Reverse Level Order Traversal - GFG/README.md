# Reverse Level Order Traversal
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given a binary tree of size N, find its reverse level order traversal. ie- the traversal must begin from the last level. </span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input :</strong>
        1
      /   \
     3     2</span>

<span style="font-size:18px"><strong>Output:</strong> 3 2 1
<strong>Explanation:</strong>
Traversing level 1 : 3 2
Traversing level 0 : 1</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input :</strong>
       10
      /  \
     20   30
    / \ 
   40  60</span>

<span style="font-size:18px"><strong>Output: </strong>40 60 20 30 10
<strong>Explanation:</strong>
Traversing level 2 : 40 60
Traversing level 1 : 20 30
Traversing level 0 : 10</span></pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:&nbsp; </strong><br>
You dont need to read input or print anything. Complete the function <strong>reverseLevelOrder() </strong>which takes the root of the tree as input parameter and returns a list containing the reverse level order traversal of the given tree.</span></p>

<p><br>
<span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(N)<br>
<strong>Expected Auxiliary Space: </strong>O(N)</span></p>

<p><br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 10^4</span></p>
</div>