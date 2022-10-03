<h2><a href="https://leetcode.com/problems/regular-expression-matching/">10. Regular Expression Matching</a></h2><h3>Hard</h3><hr><div><p>Given an input string <code>s</code> and a pattern <code>p</code>  implement regular expression matching with support for <code>'.'</code> and <code>'*'</code> where:

<ul>
	<li><code>'.'</code> Matches any single character.​​​​ </li>
	<li><code>'*'</code> Matches zero or more of the preceding element.</li>
</ul>

The matching should cover the <em>entire</em> input string (not partial).</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "aa", p = "a"
<strong>Output:</strong> false
<strong>Explanation:</strong> "a" does not match the entire string "aa".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "aa", p = "a*"
<strong>Output:</strong> true
<strong>Explanation:</strong> ".*" means "zero or more (*) of any character (.)".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 20</code></li>
    <li><code>1 &lt;= p.length &lt;= 30</code></li>
	<li><code>s</code> contains only lowercase English letters.</li>
	<li><code>p</code> contains only lowercase English letters, <code>'.'</code> and <code>'*'</code>.</li>
	<li>It is guaranteed for each appearance of the character <code>'*'</code>, there will be a previous valid character to match.</li>
</ul>
</div>