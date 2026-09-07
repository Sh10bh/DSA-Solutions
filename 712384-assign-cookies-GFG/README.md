# [Assign Cookies](https://www.geeksforgeeks.org/problems/assign-cookies/1)
## Easy
You are given an array greed[], where greed[i] represents the minimum size of cookie required to satisfy the i-th child, and an array cookie[], where cookie[j] represents the size of the j-th cookie. Each child can receive at most one cookie. A child i will be satisfied if they receive a cookie j such that cookie[j] &gt;= greed[i]. Your task is to determine the maximum number of children that can be satisfied.
Examples:
Input :&nbsp;greed[] = [1, 10, 3], cookie = [1, 2, 3]Output: 2Explanation:&nbsp;We can only assign cookie to the first and third child.
Input :&nbsp;greed[] = [10, 100], cookie = [1, 2]Output: 0Explanation:&nbsp;We can not assign cookies to any child.
Constraints:1 ≤ greed.size() ≤&nbsp; 1051 ≤ cookie.size() ≤&nbsp; 1051 ≤ greed[i] , cookie[i] ≤ 109