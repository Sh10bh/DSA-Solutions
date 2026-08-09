# [Search Pattern (Rabin-Karp Algorithm)](https://www.geeksforgeeks.org/problems/search-pattern-rabin-karp-algorithm--141631/1)
## Hard
Given two strings:


A&nbsp;text&nbsp;string in which you want to search.


A&nbsp;pattern&nbsp;string that you are looking for within the&nbsp;text.


Return all positions (0-based indexing) where the pattern&nbsp;occurs as a substring in the&nbsp;text. 
Note: If the pattern does not occur in text, return an empty list.
Examples:
Input: text = "geeksforgeeks", pattern = "geek"Output: [0, 8]
Explanation: The string "geek" occurs twice in text, one starts at index 0 and the other at index 8.
Input: text = "aabaacaadaabaaba", pattern = "aaba"
Output: [0, 9, 12]
Explanation: 
Constraints:1 ≤ text.size() ≤ 1061 ≤ pattern.size() ≤ text.size()Both the strings consist of lowercase English alphabets.