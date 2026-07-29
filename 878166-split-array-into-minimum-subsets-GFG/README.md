# [Split Array into Minimum Subsets](https://www.geeksforgeeks.org/problems/split-array-into-minimum-subsets/1)
## Easy
Given an array arr[] of distinct positive numbers. Split the array into the minimum number of subsets such that each subset contains consecutive numbers.
Examples:
Input: arr[] = [100, 56, 5, 6, 102, 58, 101, 57, 7, 103, 59]
Output: 3
Explanation: [5, 6, 7], [56, 57, 58, 59], [100, 101, 102, 103] are 3 subsequences in which numbers are consecutive.
Input: arr[] = [10, 100, 105]
Output: 3
Explanation: [10], [100] and [105] are 3 subset in which numbers are consecutive.
Constraints:1 ≤ arr.size() ≤ 1050 ≤ arr[i] ≤ 109