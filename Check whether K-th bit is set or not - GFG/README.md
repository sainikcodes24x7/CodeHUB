# Check whether K-th bit is set or not
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given a number <strong>N </strong>and a bit number <strong>K</strong>, check if <strong>K<sup>th</sup></strong>&nbsp;index bit of N is set or not. A bit is called set if it is 1. Position of set bit&nbsp;'1' should be indexed starting with 0&nbsp;from LSB side in&nbsp;binary representation of the number.</span><br>
<span style="font-size:18px"><strong>Note:</strong>&nbsp;Index is starting from 0.</span><br>
<span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input</strong>: N = 4, K = 0
<strong>Output</strong>: No
<strong>Explanation</strong>: Binary representation of 4 is 100, 
in which 0<sup>th</sup> index bit from LSB is not set. 
So, return false.</span></pre>

<p><strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input</strong>: N = 4, K = 2
<strong>Output</strong>: Yes
<strong>Explanation</strong>: Binary representation of 4 is 100, 
in which 2<sup>nd</sup> index bit from LSB is set. 
So, return true.</span></pre>

<p><strong><span style="font-size:18px">Example 3:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input</strong>: N = 500, K = 3
<strong>Output</strong>: No
<strong>Explanation</strong>: Binary representation of 500&nbsp;is 
111110100, in which 3rd index bit from LSB is not set. 
So, return false.</span></pre>

<div><br>
<strong><span style="font-size:18px">Your task:</span></strong></div>

<div><span style="font-size:18px">You don't have to read input or print anything. Your task is&nbsp;to complete the function<strong> checkKthbit </strong>that takes <strong>n </strong>and<strong> k </strong>as parameters and returns<strong> </strong>either true (if kth bit is set) or false(if kth bit is not set).</span><br>
<br>
<span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(1).<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(1).</span><br>
<br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 10<sup>9</sup><br>
0 ≤ K ≤ floor(log<sub>2</sub>(N) + 1)</span></div>
</div>