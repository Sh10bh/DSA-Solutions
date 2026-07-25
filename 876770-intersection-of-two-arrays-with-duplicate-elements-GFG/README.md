# [Intersection of Two arrays with Duplicate Elements](https://www.geeksforgeeks.org/problems/intersection-of-two-arrays-with-duplicate-elements/1)
## Easy
Given two integer&nbsp;arrays&nbsp;a[]&nbsp;and&nbsp;b[], you have to find&nbsp;the&nbsp;intersection&nbsp;of the two arrays.&nbsp;Intersection of two arrays is said to be elements that are common in both the arrays. The intersection should not have duplicate elements and the result may contain elements in any order.
Note:&nbsp;The driver code will&nbsp;sort&nbsp;the resulting array in increasing order before printing.
Examples:
Input: a[] = [1, 2, 1, 3, 1], b[] = [3, 1, 3, 4, 1]Output: [1, 3]Explanation: 1 and 3 are the only common elements and we need to print only one occurrence of common elements.
Input: a[] = [1, 1, 1], b[] = [1, 1, 1, 1, 1]Output: [1]Explanation: 1 is the only common element present in both the arrays.
Input: a[] = [1, 2, 3], b[] = [4, 5, 6]Output: []Explanation: No common element in both the arrays.
Constraints:1 ≤ a.size(), b.size() ≤ 1050 ≤ a[i], b[i] ≤ 105