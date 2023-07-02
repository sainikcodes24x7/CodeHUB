# Print adjacency list
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-family: arial, helvetica, sans-serif;"><span style="color: rgba(0, 0, 0, 0.87); font-size: 18px; background-color: #ffffff;">Given the adjacency list representation of an undirected graph<br>your task is to complete the function&nbsp;</span><span style="box-sizing: inherit; font-weight: bolder; color: rgba(0, 0, 0, 0.87); font-size: 18px; background-color: #ffffff;">printGraph()</span><span style="color: rgba(0, 0, 0, 0.87); font-size: 18px; background-color: #ffffff;"> that takes the number of vertices (V) and the adjacency list as input parameters. <br>The function should return a new adjacency list, where each adjacency list contains the <strong>vertex itself at first position </strong>then all its adjacent nodes, in the <strong>same order</strong> of the given adjacency list of that vertex.</span></span></p>
<p><br><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong>
<img src="https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/701247/Web/Other/5c5cf82d-6510-48e7-834e-311f933ce758_1685086928.png" alt="">
<strong>Output:</strong> 
0-&gt; 1-&gt; 4 
1-&gt; 0-&gt; 2-&gt; 3-&gt; 4 
2-&gt; 1-&gt; 3 
3-&gt; 1-&gt; 2-&gt; 4 
4-&gt; 0-&gt; 1-&gt; 3
<strong>Explanation</strong>:
As 0,1 and 3 is connected to 4 so 4th row
of the list containing 4 and its connected
nodes 0,1 and 3 and we have to add those in
sorted order and same for every row.
</span>
</pre>
<p><br><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong>
<img src="https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/701247/Web/Other/e8e7865d-f04d-4d93-bf1f-c6b6baee639a_1685086929.png" alt="">

<strong>Output:</strong> 
0-&gt; 2-&gt; 3 
1-&gt; 2 
2-&gt; 0-&gt; 1 
3-&gt; 0
<strong>Explanation</strong>:
As 2 and 3 is connected to 0 so 0th row
of the list containing 0 and its connected 
nodes 2 and 3 and we have to add those in
sorted order and same for every row. 
</span>
</pre>
<p><br><span style="font-size: 18px;"><strong>Your task:</strong><br>You dont need to read input or print anything. Your task is to complete the function&nbsp;<strong>printGraph()</strong> which takes the integer V denoting the number of vertices and adjacency list as input parameters and returns the list of list&nbsp; contains the node itself at first position with its connected nodes(as same as it is given in input adjacency&nbsp; list).</span></p>
<p><br><span style="font-size: 18px;"><strong>Expected Time Complexity:&nbsp;</strong>O(V + E)<br><strong>Expected Auxiliary Space:&nbsp;</strong>O(V + E)</span></p>
<p><br><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ V, E ≤ 10<sup>4</sup></span></p></div>