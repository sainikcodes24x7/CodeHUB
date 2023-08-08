# Distribute N candies among K people
## Medium
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given <strong>N</strong> candies and <strong>K</strong> people. In the first turn, the first person gets 1 candy, the second gets 2 candies, and so on till K people. In the next turn, the first person gets K+1 candies, the second person gets K+2 candies and so on. If the number of candies is less than the required number of candies at every turn, then the person receives the remaining number of candies. Find the total number of candies every person has at the end.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 7, K = 4
<strong>Output:
</strong>1 2 3 1
<strong>Explanation:</strong>
At the first turn, the fourth person
has to be given 4 candies, but there is
only 1 left, hence he takes only one. </span>
</pre>

<div><span style="font-size:18px"><strong>Example 2:</strong></span></div>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 10, K = 3
<strong>Output :</strong>
5 2 3</span>
<span style="font-size:18px"><strong>Explanation:</strong>
At the second turn first one receives
4 and then we have no more candies left. </span>

</pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You don't need to read input or print anything. Your task is to complete the function <strong>distributeCandies()</strong>&nbsp;which takes 2 integers N and K as input and returns a list, where the ith integer denotes the number of candies the ith person gets.</span></p>

<p><br>
<span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(logN+K)<br>
<strong>Expected Auxiliary Space:</strong> O(K)</span></p>

<p><br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 10<sup>8</sup><br>
1 ≤ K ≤ 100</span></p>
</div>