# [Sum of Pairwise ANDs](https://www.geeksforgeeks.org/problems/sum-of-products5049/1)
## Medium
Given an array arr[] of integers, calculate the sum of bitwise AND for all pairs of elements such that the first index is less than the second index.
Examples:
Input: arr = [5, 10, 15]
Output: 15
Explanation: Consider all pairs of elements where the first index is less than the second index (i &lt; j).
For the array [5, 10, 15], the valid pairs are:
(5, 10)  -&gt; 5 &amp; 10  = 0
(5, 15)  -&gt; 5 &amp; 15  = 5
(10, 15) -&gt; 10 &amp; 15 = 10
Now, add all these results: 0 + 5 + 10 = 15
So, the total sum of bitwise ANDs for all such pairs is 15
Input: arr = [10, 20, 30, 40]
Output: 46
Explanation: Consider all pairs of elements where the first index is less than the second index (i &lt; j).
For the array [10, 20, 30, 40], the valid pairs are:
(10, 20) -&gt; 10 &amp; 20 = 0
(10, 30) -&gt; 10 &amp; 30 = 10
(10, 40) -&gt; 10 &amp; 40 = 8
(20, 30) -&gt; 20 &amp; 30 = 20
(20, 40) -&gt; 20 &amp; 40 = 0
(30, 40) -&gt; 30 &amp; 40 = 8
Now, add all these results: 0 + 10 + 8 + 20 + 0 + 8 = 46
So, the total sum of bitwise ANDs for all such pairs is 46
