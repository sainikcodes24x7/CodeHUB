# Bit Manipulation
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given a 32 bit unsigned&nbsp;integer <strong>num</strong> and an integer <strong>i</strong>. Perform following operations on the number -&nbsp;</span></p>

<p><span style="font-size:18px">1. <strong>Get</strong> ith bit</span></p>

<p><span style="font-size:18px">2. <strong>Set</strong> ith bit</span></p>

<p><span style="font-size:18px">3. <strong>Clear</strong> ith bit</span></p>

<p><strong><span style="font-size:18px">Note :</span> </strong><span style="font-size:18px">For better understanding, we are starting bits from 1 instead 0. (1-based)</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: </strong>70 3</span>
<span style="font-size:18px"><strong>Output: </strong>1 70 66</span>
<span style="font-size:18px"><strong>Explanation: </strong>Bit at the 3rd position from LSB is 1. (1 0 0 0 <strong>1</strong> 1 0)</span>
<span style="font-size:18px">The value of the given number after setting the 3rd bit is 70. </span>
<span style="font-size:18px">The value of the given number after clearing 3rd bit is 66. (1 0 0 0 <strong>0</strong> 1 0)</span>
</pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: </strong>8 1</span>
<span style="font-size:18px"><strong>Output: </strong>0 9 8</span>
<span style="font-size:18px"><strong>Explanation:</strong> Bit at the first position from LSB is 0. (1 0 0 <strong>0</strong>)</span>
<span style="font-size:18px">The value of the given number after setting the 1st bit is 9. (1 0 0 <strong>1</strong>)</span>
<span style="font-size:18px">The value of the given number after clearing 1st bit is 8. (1 0 0 <strong>0</strong>)</span></pre>

<p>&nbsp;</p>

<p><strong><span style="font-size:18px">Your Task:</span></strong></p>

<p><span style="font-size:18px">Complete the function <strong>bitManipulation()</strong> which takes two integers num and i as input and prints the results after each operation separted by a space in the&nbsp;same line. You don't have to print any new lines after printing the output, that will be handled by driver code.</span></p>

<p>&nbsp;</p>

<p><strong><span style="font-size:18px">Constraints:</span></strong></p>

<p><span style="font-size:18px">0&lt;=num&lt;=10<sup>9</sup></span></p>

<p><span style="font-size:18px">1&lt;=i&lt;=32</span></p>

<p>&nbsp;</p>
</div>