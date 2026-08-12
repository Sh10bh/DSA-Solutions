# [Equal Sum](https://www.geeksforgeeks.org/problems/equal-sum0810/1)
## Medium
Given an array arr. Determine if there exists an element in the array such that the sum of the elements on its left is equal to the sum of the elements on its right.
 If there are no elements to the left/right, then the sum is considered to be zero.&nbsp;
Examples:
Input: arr[] = [1, 2, 3, 3]
Output: true
Explanation: Consider 1-based indexing i = 3, for [1, 2] sum is 3 and for [3] sum is also 3.

Input: arr[] = [1, 5]
Output: false
Explanation:&nbsp;No such index present.

Constraints:1 ≤ arr.size() ≤ 105&nbsp;1 ≤ arr[i] ≤ 106