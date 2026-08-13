# [Replace Elements by Ranks](https://www.geeksforgeeks.org/problems/convert-an-array-to-reduced-form1101/1)
## Easy
Given an array arr[] of n integers, convert it into its reduced form. In the reduced form, each element is replaced by its rank.&nbsp;The smallest should be replaced with 0, the second smallest with 1, and the largest is replaced with n - 1.

The relative positions of the elements in the array must remain unchanged.
For repeating elements, the element appearing earlier in the original array must be of smaller rank than the one appearing later.
You need to modify the array in-place and do not return anything.

Examples:
Input: arr[] = [10, 40, 20]
Output: [0, 2, 1]
Explanation: The elements in sorted order are 10, 20, 40 and assigned ranks 0, 1, and 2 respectively.

Input: arr[] = [0, 2, 1]
Output: [0, 2, 1]
Explanation: The array is already in reduced form..
Input: arr[] = [1, 5, 3, 4, 3]
Output: [0, 4, 1, 3, 2]
Explanation: 1 gets rank 0. The first 3 gets rank 1, the second 3 as rank 2, 4 as rank 3 and 5 as rank 4.
Constraints:1 ≤ n ≤ 1051 ≤ arr[i] ≤ 106