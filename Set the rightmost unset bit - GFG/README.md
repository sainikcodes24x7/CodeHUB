# Set the rightmost unset bit
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given a non-negative number <strong>N</strong>. The problem is to set the rightmost unset bit in the binary representation of <strong>N</strong>. If there are no unset bits, then just leave the number as it is.</span></p>

<p><strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
N = 6</span>
<span style="font-size:18px"><strong>Output:</strong>
7</span>
<span style="font-size:18px"><strong>Explanation:</strong>
The binary representation of 6 is 110.
After setting right most bit it becomes
111 which is 7.</span></pre>

<p><strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
N = 15</span>
<span style="font-size:18px"><strong>Output:</strong>
15</span>
<span style="font-size:18px"><strong>Explanation:</strong>
The binary representation of 15 is 1111.
As there is no unset bit it remains the
same.</span></pre>

<p><span style="font-size:18px"><strong>Your Task:&nbsp;</strong>&nbsp;<br>
You don't need to read input or print anything. Your task is to complete the function <strong>setBit</strong>()&nbsp;which takes an integer N as input parameter&nbsp;and returns the integer after setting a rightmost unset bit.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(LogN)<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(1)</span></p>

<p><br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= N &lt;= 10<sup>9</sup></span></p>
</div>