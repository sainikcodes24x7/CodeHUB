"""
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
Below is one possible representation of s1 = "great":
    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.
For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".
    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".
Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".
    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".
Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
Example 1:
Input: s1 = "great", s2 = "rgeat"
Output: true
Example 2:
Input: s1 = "abcde", s2 = "caebd"
Output: false
"""
"""
Algorithm:
recursively call isScramble(s1[:i], s2[:i]) and isScramble(s1[i:], s2[i:]),
                    if both true, return true
                 isScramble(s1[:i], s2[s2.length - i:]) and isScramble(s1[i:], s2[:s2.length - i]),
                    if both true, return true
Else: return false
Declare a map {(s1, s2): bool} to memorize valid substring paris from s1 and s2.
Check (s1, s2) in map in the beginning of the function: if find it, return map[(s1, s2)]
Prunning by check len(s1) == len(s2) and sorted(s1) == sorte(s2)
"""
"""
@param {str} s1
@param {str} s2
@return {bool}
"""
class Solution:
    def __init__(self):
        self.map = {} # key: (s1, s2), value: bool

    def isScramble(self, s1, s2):
        if (s1, s2) in self.map:
            return self.map[(s1, s2)]

        if len(s1) != len(s2):
            # Memorization
            self.map[(s1, s2)] = False
            return False

        if s1 == s2:
            # Memorization
            self.map[(s1, s2)] = True
            return True

        # Prunning
        if sorted(s1) != sorted(s2):
            # Memorization
            self.map[(s1, s2)] = False
            return False

        # i starts from 1, otherwise s[0:0] causes RecursionError
        for i in range(1, len(s1)):
            if self.isScramble(s1[:i], s2[:i]) and self.isScramble(s1[i:], s2[i:]):
                return True

            if self.isScramble(s1[:i], s2[len(s2)-i:]) and self.isScramble(s1[i:], s2[:len(s2)-i]):
                return True

        # Memorization
        self.map[(s1, s2)] = False
        return False
