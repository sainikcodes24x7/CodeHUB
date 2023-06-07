# Floor in a Sorted Array
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given a sorted array <strong>arr</strong>[] of size <strong>N</strong> without duplicates, and given a value <strong>x</strong>. Floor of x is defined as the largest element <strong>K</strong> in arr[] such that K is smaller than or equal to x.&nbsp;Find the index of K(0-based indexing).</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 7, x = 0 
arr[] = {1,2,8,10,11,12,19}
<strong>Output: </strong>-1<strong>
Explanation: </strong>No element less 
than 0 is found. So output 
is "<strong>-1</strong>".</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 7, x = 5 
arr[] = {1,2,8,10,11,12,19}
<strong>Output: </strong>1<strong>
Explanation: </strong>Largest Number less than 5 is
<strong>2 (i.e K = 2)</strong>, whose index is <strong>1</strong>(0-based 
indexing).</span>
</pre>

<p><span style="font-size:18px"><strong>Your&nbsp;Task:</strong><br>
The task is to complete the function <strong>findFloor</strong>() which returns an&nbsp;integer denoting the index value of K&nbsp;or return <strong>-1</strong> if there isn't any such number.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(log N).<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(1).</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 10<sup>7</sup><br>
1 ≤ arr[i] ≤ 10<sup>18</sup><br>
0 ≤ X&nbsp;≤<sup> </sup>arr[n-1]</span></p>
</div>